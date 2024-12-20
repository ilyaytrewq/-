#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *append_to_list(Node *head,Node **tail, int data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL){
        head = new_node;
    }
    else {
        (*tail)->next = new_node;
    }
    *tail = new_node;
    
    return head;
}

Node *delete(Node *head, int lenght){
    if (lenght % 2 == 0){
        return head;
    }
    Node *cur = head;
    Node *prev = NULL;
    for (int i = 0; i < lenght / 2; i++){
        prev = cur;
        cur = cur->next;
    }
    if (prev){
        prev->next = cur->next;
    }
    else{
        head = cur->next;
    }
    free(cur);
    return head;
}
void free_list(Node *head){
    Node *cur = head;
    while (cur != NULL){
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }
}

void watch(Node **word, int word_length, FILE *out, int *first_word){
    *word = delete (*word, word_length);
    if (word_length == 1){
        return;
    }

    if (*first_word == 0){
        fputc(' ', out);
    }

    Node *cur = *word;
    while (cur){
        fputc(cur->data, out);
        cur = cur->next;
    }
    *first_word = 0;
    free_list(*word);
    *word = NULL;
}

int main(void){
    FILE *file = fopen("words.in", "r");
    FILE *out = fopen("words.out", "w");
    Node *list = NULL, *tail = NULL;
    char ch;
    int curr = 0;
    int first_word = 1;
    while ((ch = fgetc(file)) != EOF){
        if (ch == ' ' || ch == '.'){
            if (curr > 0){
                watch(&list, curr, out, &first_word);
                curr = 0;
            }
            if (ch == '.'){
                break;
            }
        }
        else{
            list = append_to_list(list, &tail, ch);
            curr++;
        }
    }
    fputc('.', out);
    fclose(file);
    fclose(out);
    return 0;
}
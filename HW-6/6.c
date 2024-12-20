#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

list *NewNode(int x)
{
    list *node = calloc(1, sizeof(list));
    if (node == 0)
    {
        printf("Error on calloc\n");
        exit(-1);
    }
    node->data = x;
    return node;
}

int find(list *head, int val)
{
    list *cur = head;
    while (cur)
    {
        if (cur->data == val)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void freeList(list *root)
{
    list *cur = root, *tmp;
    while (cur)
    {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");
    if (f == 0)
    {
        printf("NO FILE\n");
        exit(-1);
    }

    int x;
    fscanf(f, "%d ", &x);
    list *a = NewNode(x);
    list *cur = a;
    while (x != -1)
    {
        fscanf(f, "%d", &x);
        cur->next = NewNode(x);
        cur = cur->next;
    }
    
    fscanf(f, "%d ", &x);
    list *b = NewNode(x);
    cur = b;
    while (x != -1)
    {
        fscanf(f, "%d", &x);
        cur->next = NewNode(x);
        cur = cur->next;
    }
    fclose(f);

    f = fopen("output.txt", "w");
    cur = a;
    while (cur)
    {
        if (find(b, cur->data) == 0)
        {
            fprintf(f, "%d ", cur->data);
        }
        cur = cur->next;
    }
    freeList(a);
    freeList(b);
    
    fclose(f);
    return 0;
}

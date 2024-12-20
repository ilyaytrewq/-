#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie
{
    char val;
    struct trie *FirstChild;
    struct trie *Neighbour;
} trie;

trie *CreateNode(char c)
{
    trie *node = malloc(sizeof(trie) * 1);
    if (node == NULL)
    {
        printf("Error on malloc\n");
        exit(-1);
    }
    node->val = c;
    node->FirstChild = 0;
    node->Neighbour = 0;
    return node;
}

trie *findNode(trie *vertex, int c)
{
    trie *cur = vertex->FirstChild;
    while (cur != NULL)
    {
        if (cur->val == c)
            return cur;
        cur = cur->Neighbour;
    }
    return NULL;
}

void addNode(trie *vertex, trie *node)
{
    if (vertex->FirstChild == NULL)
    {
        vertex->FirstChild = node;
        return;
    }
    trie *cur = vertex->FirstChild;
    while (cur->Neighbour != NULL)
        cur = cur->Neighbour;
    cur->Neighbour = node;
}

int dfs(trie *vertex)
{
    if (vertex == NULL)
        return 0;
    int ans = 0;
    trie *cur = vertex, *tmp;
    while (cur)
    {
        ans += dfs(cur->FirstChild) + 1;
        tmp = cur;
        cur = cur->Neighbour;
        free(tmp);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    char *s = malloc(2001);
    scanf("%2000s", s);
    int n = strlen(s);
    trie *root = CreateNode(0);
    for (int i = 0; i < n; ++i)
    {
        trie *vertex = root;
        for (int j = i; j < n; ++j)
        {
            char c = s[j];
            trie *next = findNode(vertex, c);
            if (next == NULL)
            {
                next = CreateNode(c);
                addNode(vertex, next);
            }
            vertex = next;
        }
    }
    printf("%d\n", dfs(root));
    free(s);
    return 0;
}
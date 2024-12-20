#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ull unsigned long long
#define MAX_SIZE 4001
#define Alphabet 26

typedef struct trie
{
    struct trie *to[Alphabet];
    char *s[Alphabet];
    int *used[Alphabet];
} trie;

trie *CreateNode(void)
{
    trie *node = malloc(sizeof(trie));
    if (node == NULL)
    {
        printf("Error in creation\n");
        exit(-1);
    }
    for (int i = 0; i < Alphabet; ++i)
    {
        node->to[i] = NULL;
        node->s[i] = NULL;
        node->used[i] = NULL;
    }
    return node;
}

int countChildren(trie *node)
{
    int cnt = 0;
    for (int i = 0; i < Alphabet; ++i)
    {
        if (node->to[i] != NULL)
        {
            cnt++;
        }
    }
    return cnt;
}

void addString(trie *root, char *s)
{
    trie *cur = root;
    int it = 0, n = strlen(s);
    while (it < n)
    {
        int c = s[it] - 'a';
        if (cur->to[c] == NULL)
        {
            cur->to[c] = CreateNode();
            cur->s[c] = malloc(n - it + 1);
            memcpy(cur->s[c], s + it, n - it);
            cur->s[c][n - it] = '\0';
            cur->used[c] = calloc(strlen(cur->s[c]), sizeof(int));
            return;
        }

        int m = strlen(cur->s[c]);
        int pref = 0;

        while (pref < n && pref < m && cur->s[c][pref] == s[it + pref])
            ++pref;

        if (pref == m && countChildren(cur->to[c]) == 0)
        {
            free(cur->s[c]);
            cur->s[c] = malloc(n - it + 1);
            memcpy(cur->s[c], s + it, n - it);
            cur->s[c][n - it] = '\0';
            cur->used[c] = calloc(strlen(cur->s[c]), sizeof(int));
            return;
        }

        if (pref == m)
        {
            it += pref;
            cur = cur->to[c];
            continue;
        }

        if (it + pref == n)
            return;

        trie *node = CreateNode();

        node->to[cur->s[c][pref] - 'a'] = cur->to[c];

        if(node->s[cur->s[c][pref] - 'a'] != NULL){
            free(node->s[cur->s[c][pref] - 'a']);
        }
        node->s[cur->s[c][pref] - 'a'] = malloc(m - pref + 1);
        memcpy(node->s[cur->s[c][pref] - 'a'], cur->s[c] + pref, m - pref + 1);
        node->s[cur->s[c][pref] - 'a'][m - pref] = '\0';
        
        node->used[cur->s[c][pref] - 'a'] = calloc(strlen(cur->s[c] + pref), sizeof(int));


        node->to[s[it + pref] - 'a'] = CreateNode();
        
        if(node->s[s[it + pref] - 'a'] != NULL){
            free(node->s[s[it + pref] - 'a']);
        }
        node->s[s[it + pref] - 'a'] = malloc(n - it - pref + 1);
        memcpy(node->s[s[it + pref] - 'a'], s + it + pref, n - it - pref + 1);
        node->s[s[it + pref] - 'a'][n - it - pref] = '\0';

        node->used[s[it + pref] - 'a'] = calloc(strlen(s + it + pref), sizeof(int));

        cur->to[c] = node;
        cur->s[c] = realloc(cur->s[c], pref + 1);
        cur->s[c][pref] = '\0';
        cur->used[c] = realloc(cur->used[c], pref * sizeof(int));
        return;
    }
}

void freeTrie(trie *node)
{
    if (node == NULL)
        return;

    for (int i = 0; i < Alphabet; ++i)
    {
        if(node->to[i] != NULL){
            freeTrie(node->to[i]);
            free(node->to[i]);
        }
        if(node->s[i] != NULL){
            free(node->s[i]);
        }
        if(node->used[i] != NULL)
            free(node->used[i]);
    }
}

int main(int argc, char const *argv[])
{
    char *s1 = calloc(4001, 1), *s2 = calloc(4001, 1);
    if (s1 == NULL || s2 == NULL)
    {
        printf("Error on calloc");
        return -1;
    }
    scanf("%4000s %4000s", s1, s2);

    int n = strlen(s1), m = strlen(s2);
    trie *root = CreateNode();

    for (int i = 0; i < n; ++i)
        addString(root, s1 + i);

    int ans = 1;
    for (int i = 0; i < m; ++i)
    {
        int curInd = s2[i] - 'a', curpos = 0, curlen = -1;
        trie *cur = root;

        if (cur->to[curInd] == NULL)
            continue;

        curlen = strlen(cur->s[curInd]);
        for (int j = i; j < m; ++j)
        {
            if (curpos == curlen)
            {
                cur = cur->to[curInd];
                curInd = s2[j] - 'a';
                if (cur->to[curInd] == NULL)
                    break;
                curlen = strlen(cur->s[curInd]);
                curpos = 0;
            }
            if(s2[j] != cur->s[curInd][curpos])
                break;
            ans += (cur->used[curInd][curpos] ^ 1);
            cur->used[curInd][curpos] = 1;
            curpos++;
        }
    }

    printf("%d\n", ans);
    freeTrie(root);
    free(s1);
    free(s2);
    return 0;
}
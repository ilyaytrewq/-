#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ull unsigned long long

typedef struct turple{
    int first;
    ull second;
    unsigned int val;
} turple;

inline char *readString(FILE *f)
{
    int size = 0;
    char *s = malloc(101);
    s[size++] = fgetc(f);
    while (s[size - 1] != ' ' && s[size - 1] != '\n' && s[size - 1] != EOF)
        s[size++] = fgetc(f);

    s[size - 1] = '\0';
    --size;
    s = realloc(s, size + 1);
    return s;
}

inline int gethash1(char *s, int p, int mod)
{
    int hash = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        hash = (1ll * hash * p + s[i]) % mod;
    }
    return hash;
}

inline ull gethash2(char *s, int p)
{
    ull hash = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        hash = hash * p + s[i];
    }
    return hash;
}

int turplecmp(turple a, turple b){
    if(a.first < b.first || (a.first == b.first && a.second < b.second))
        return -1;
    if(a.first == b.first && a.second == b.second)
        return 0;
    return 1;
}

int cmp(const void *arg1, const void *arg2){
    return turplecmp(*(turple *)arg1, *(turple *)arg2);
}

turple * findTurple(turple *a, turple x, int n){
    int l = 0, r = n;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(turplecmp(a[m], x) == 0)
            return &a[m];
        if(turplecmp(a[m], x) < 0){
            l = m;
        }
        else{
            r = m;
        }
    }
    return (turplecmp(a[l], x) == 0 ? &a[l] : NULL);
}

int main(int argc, char const *argv[])
{
    const int p = 179, mod = 1e9 + 7;
    
    FILE *f = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    if (f == 0)
    {
        printf("NO FILE\n");
        exit(-1);
    }

    int n, m;
    fscanf(f, "%d\n", &n);
    turple *a = malloc(n * sizeof(turple));
    if(a == NULL){
        printf("Error on malloc\n");
        return -1;
    }

    for (int i = 0; i < n; ++i)
    {
        char *s = readString(f);
        fscanf(f, "%u\n", &a[i].val);
        a[i].first = gethash1(s, p, mod);
        a[i].second = gethash2(s, p);
        free(s);
    }

    qsort(a, n, sizeof(turple), cmp);
    for(int i = 1; i < n; ++i){
        if(turplecmp(a[i - 1], a[i]) == 0){
            fprintf(out, "Equal hash\n");
            return -1;
        }
    }

    fscanf(f, "%d\n", &m);
    for (int i = 0; i < m; ++i)
    {
        char *s = readString(f);
        turple x;
        x.first = gethash1(s, p, mod);
        x.second = gethash2(s, p);
        turple *res = findTurple(a, x, n);
        if (res == NULL)
        {
            fprintf(out, "-1\n");
        }
        else
        {
            fprintf(out, "%u\n", res->val);
        }
        free(s);
    }
    free(a);
    fclose(f);
    fclose(out);
    return 0;
}

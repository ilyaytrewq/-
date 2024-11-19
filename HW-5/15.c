#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

void *xrealloc(void *ptr, int sz)
{
    ptr = realloc(ptr, sz);
    if (ptr == 0)
    {
        printf("Error on realloc\n");
        exit(-1);
    }
    return ptr;
}

void *xcalloc(int sz)
{
    int *mem = malloc(sz);
    if (mem == 0)
    {
        printf("Error on malloc\n");
        exit(-1);
    }
    return mem;
}

char *readString(void)
{
    int sz = 1, cap = 4;
    char *s = xcalloc(cap);
    s[0] = getchar();
    while (s[sz - 1] == '?' || isdigit(s[sz - 1]))
    {
        if (sz == cap)
        {
            cap *= 2;
            s = xrealloc(s, cap);
        }
        s[sz++] = getchar();
    }
    s[sz - 1] = '\0';
    s = xrealloc(s, sz);
    return s;
}

void reverse(char *s, int n)
{
    for (int i = 0; i < n / 2; ++i)
    {
        char tmp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = tmp;
    }
}

int left(char c)
{
    return (c == '?' ? 0 : c - '0');
}

int right(char c)
{
    return (c == '?' ? 9 : c - '0');
}

int main(int argc, char const *argv[])
{
    char *a = readString();
    char *b = readString();
    char *c = readString();
    int n = strlen(a), m = strlen(b), k = strlen(c);
    reverse(a, n);
    reverse(b, m);
    reverse(c, k);
    int p = max(n, max(k, m));
    a = xrealloc(a, p + 1);
    b = xrealloc(b, p + 1);
    c = xrealloc(c, p + 1);
    for (int i = 0; i < p; ++i)
    {
        if (i >= n)
            a[i] = '0';
        if (i >= m)
            b[i] = '0';
        if (i >= k)
            c[i] = '0';
    }
    a[p] = '\0';
    b[p] = '\0';
    c[p] = '\0';
    int ***dp = xcalloc(p * sizeof(int **));
    int **can = xcalloc(p * sizeof(int *));
    int **pr = xcalloc(p * sizeof(int *));
    for (int i = 0; i < p; ++i)
    {
        dp[i] = xcalloc(2 * sizeof(int *));
        can[i] = xcalloc(2 * sizeof(int));
        pr[i] = xcalloc(2 * sizeof(int));
        for (int j = 0; j < 2; ++j)
        {
            dp[i][j] = xcalloc(3 * sizeof(int));
            pr[i][j] = -1;
            for (int q = 0; q < 3; ++q)
                dp[i][j][q] = -1;
        }
    }
    for (int i = 0; i < p; ++i)
    {
        for (int x = left(a[i]); x <= right(a[i]); ++x)
        {
            for (int y = left(b[i]); y <= right(b[i]); ++y)
            {
                for (int z = left(c[i]); z <= right(c[i]); ++z)
                {
                    for (int q = 0; q < 2 - (i == 0); ++q)
                    {
                        if ((i == 0 || can[i - 1][q]) ? 1 : 0)
                        {
                            if ((x + y + q) % 10 == z)
                            {
                                int f = (x + y + q) / 10;
                                can[i][f] = 1;
                                dp[i][f][0] = x;
                                dp[i][f][1] = y;
                                dp[i][f][2] = z;
                                pr[i][f] = q;
                            }
                        }
                    }
                }
            }
        }
    }
    if (can[p - 1][0])
    {
        int cur_pos = p - 1, f = 0;
        while (cur_pos > -1)
        {
            a[cur_pos] = dp[cur_pos][f][0] + '0';
            b[cur_pos] = dp[cur_pos][f][1] + '0';
            c[cur_pos] = dp[cur_pos][f][2] + '0';
            f = pr[cur_pos][f];
            cur_pos--;
        }
        reverse(a, n);
        reverse(b, m);
        reverse(c, k);
        a[n] = '\0';
        b[m] = '\0';
        c[k] = '\0';
        printf("%s+", a);
        printf("%s=", b);
        printf("%s\n", c);
    }
    else
    {
        printf("No\n");
    }
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < 2; ++j)
            free(dp[i][j]);
        free(pr[i]);
        free(can[i]);
        free(dp[i]);
    }
    free(dp);
    free(can);
    free(pr);
    free(a);
    free(b);
    free(c);
    return 0;
}

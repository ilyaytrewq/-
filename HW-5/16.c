#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xcalloc(int cnt, int size)
{
    void *mem = calloc(cnt, size);
    if (mem == 0)
    {
        printf("Error on malloc\n");
        exit(-1);
    }
    return mem;
}

int **mult(int **a, int **b, int n, int k, int m, int mod, int del)
{
    int **c = xcalloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        c[i] = xcalloc(m, sizeof(int));
        for (int j = 0; j < m; ++j)
        {
            for (int q = 0; q < k; ++q)
            {
                c[i][j] = (c[i][j] + 1ll * a[i][q] * b[q][j]) % mod;
            }
        }
    }
    if (del)
    {
        for (int i = 0; i < k; ++i)
            free(b[i]);
        free(b);
    }
    return c;
}

int **binpow(int **a, int exp, int n, int mod)
{
    if (exp == 1)
    {
        int **ans = xcalloc(n, sizeof(int *));
        for (int i = 0; i < n; ++i)
        {
            ans[i] = xcalloc(n, sizeof(int));
            memcpy(ans[i], a[i], n * sizeof(int));
        }
        return ans;
    }
    else if (exp % 2 == 1)
        return mult(a, binpow(a, exp - 1, n, mod), n, n, n, mod, 1);
    else
    {
        int **tmp = binpow(a, exp / 2, n, mod);
        return mult(tmp, tmp, n, n, n, mod, 1);
    }
}

int main(int argc, char const *argv[])
{
    int k, n, mod;
    scanf("%d %d %d", &k, &n, &mod);
    int **matrix = xcalloc(k, sizeof(int *));
    int **f = xcalloc(k, sizeof(int *));
    for (int i = k - 1; i > -1; --i)
    {
        f[i] = xcalloc(1, sizeof(int));
        scanf("%d", &f[i][0]);
        f[i][0] %= mod;
    }
    for (int i = 0; i < k; ++i)
    {
        matrix[i] = xcalloc(k, sizeof(int));
        scanf("%d", &matrix[0][i]);
        if (i > 0)
            matrix[i][i - 1] = 1;
    }
    if (n <= k)
    {
        printf("%d\n", f[k - n][0]);
        return 0;
    }
    int **pow_matrix = binpow(matrix, n - k, k, mod);
    int **ans = mult(pow_matrix, f, k, k, 1, mod, 0);
    printf("%d\n", ans[0][0]);
    for (int i = 0; i < k; ++i)
    {
        free(pow_matrix[i]);
        free(ans[i]);
        free(matrix[i]);
        free(f[i]);
    }
    free(pow_matrix);
    free(ans);
    free(matrix);
    free(f);
    return 0;
}

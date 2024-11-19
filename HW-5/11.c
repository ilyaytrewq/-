#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

void *xmalloc(int size)
{
    void *mem = malloc(size);
    if (mem == 0)
    {
        printf("Error on malloc\n");
        exit(-1);
    }
    return mem;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    unsigned int **a = xmalloc(n * sizeof(unsigned int *));
    for (int i = 0; i < n; ++i)
    {
        a[i] = xmalloc(m * sizeof(unsigned int));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%u", &a[i][j]);
        }
    }
    unsigned int *dp_prev = xmalloc(n * sizeof(unsigned int));
    for (int i = 0; i < n; ++i)
    {
        dp_prev[i] = a[i][0];
    }
    for (int j = 1; j < m; ++j)
    {
        unsigned int *dp_new = xmalloc(n * sizeof(unsigned int));
        for (int i = 0; i < n; ++i)
        {
            dp_new[i] = dp_prev[i];
            if (i > 0)
            {
                dp_new[i] = max(dp_new[i], dp_prev[i - 1]);
            }
            if (i + 1 < n)
            {
                dp_new[i] = max(dp_new[i], dp_prev[i + 1]);
            }
            dp_new[i] += a[i][j];
        }
        for(int i = 0; i < n; ++i){
            dp_prev[i] = dp_new[i];
        }
        free(dp_new);
    }
    unsigned int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp_prev[i]);
    }
    printf("%u\n", ans);
    for (int i = 0; i < n; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(dp_prev);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void *xmalloc(long long size)
{
    void *mem = malloc(size);
    if (mem == 0)
    {
        printf("Error on malloc happened\n");
        exit(-1);
    }
    return mem;
}

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);
    long long **a = xmalloc(n * sizeof(long long*));
    long long **b = xmalloc(n * sizeof(long long*));
    for(long long i = 0; i < n; ++i){
        a[i] = xmalloc(n * sizeof(long long));
        b[i] = xmalloc(n * sizeof(long long));
    }
    for(long long i = 0; i < n;++i){
        for(long long j = 0; j < n; ++j){
            scanf("%lld %lld", &a[i][j], &b[i][j]);   
        }
    }
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < n; ++j){
            printf("%lld %lld ", a[j][i], -b[j][i]);
        }
        printf("\n");
    }
    free(a);
    free(b);
    return 0;
}

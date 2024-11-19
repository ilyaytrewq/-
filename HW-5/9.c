#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int *x = malloc(k * sizeof(int));
    int *y = malloc(k * sizeof(int));
    if(x == 0 || y == 0){
        printf("Error on malloc\n");
        exit(-1);
    }
    for(int i = 0; i < k; ++i){
        scanf("%d %d", &x[i], &y[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int mn = (n > m ? n : m) * 2 + 2;
            for(int q = 0; q < k; ++q){
                int t = abs(y[q] - i) + abs(x[q] - j);
                mn = (mn < t ? mn : t);
            }
            ans = (ans > mn ? ans : mn);
        }
    }
    printf("%d\n", ans);
    free(x);
    free(y);
    return 0;
}

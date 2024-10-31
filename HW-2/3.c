#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[1000000];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    int b[10000000];
    for(int i = 0; i < m; ++i){
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < (n > m ? n : m); ++i){
        if(i < n){
            printf("%d ", a[i]);
        }
        if(i < m){
            printf("%d ", b[i]);
        }
    }

    return 0;
}

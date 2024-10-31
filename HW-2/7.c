#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[10000];
    if(n > 10000){
        printf("No\n");
        return 0;
    }
    for(int i = 0; i < n; ++i){
        a[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(x <= 0 || x > n || a[x - 1]++ == 1){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}

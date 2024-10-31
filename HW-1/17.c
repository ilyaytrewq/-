#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        ans ^= x;
    }    
    printf("%d", ans);
    return 0;
}
#include <stdio.h>
#include <limits.h>

int main(void){
    int n;
    scanf("%d", &n);
    int mx = -1, mn = INT_MAX;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(mx < x){
            mx = x;
        }
        if(mn > x){
            mn = x;
        }
    }
    printf("%d\n", mx - mn);
    return 0;
}
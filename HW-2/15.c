#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[1000000];
    int xr = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        xr ^= a[i];
    }
    int mask = xr - (xr & (xr - 1));
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] & mask){
            ans1 ^= a[i];
        }
        else{
            ans2 ^= a[i];
        }
    }
    if(ans1 > ans2){
        int tmp = ans1;
        ans1 = ans2;
        ans2 = tmp;
    }
    printf("%d %d", ans1, ans2);
    return 0;
}

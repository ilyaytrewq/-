#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(x > mx1){
            mx2 = mx1;
            mx1 = x;
        }
        else if(x > mx2){
            mx2 = x;
        }
        if(x < mn1){
            mn2 = mn1;
            mn1 = x;
        }
        else if(x < mn2){
            mn2 = x;
        }
    }
    int ans1 = -1, ans2 = -1;
    if(1ll * mx1 * mx2 > 1ll * mn1 * mn2){
        ans1 = mx2;
        ans2 = mx1;
    }
    else {
        ans1 = mn1;
        ans2 = mn2;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}

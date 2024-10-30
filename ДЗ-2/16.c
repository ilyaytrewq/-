#include <stdio.h>

int a[1500000];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int all_xr = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        all_xr ^= a[i];
    }
    int x = 0, y = 0;
    int bit = -1;
    for(int p = 0; p < 32; ++p){
        int mask = (1 << p);
        x = 0, y = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] & mask){
                x ^= a[i];
            }
            else{
                y ^= a[i];
            }
        }
        if(x != 0 && y != 0){
            bit = p;
            break;
        }
    }
    int cnt_x = 0, cnt_y = 0;
    for(int i = 0; i < n; ++i){
        if((a[i] & (1 << bit)) != 0 && a[i] == x){
            cnt_x++;
        }
        if((a[i] & (1 << bit)) == 0 && a[i] == y){
            cnt_y++;
        }
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = 0; i < n; ++i){
        if(cnt_x == 1 && a[i] == x){
            ans1 = x;
            a[i] = 0;
            break;
        }
        if(cnt_y == 1 && a[i] == y){
            ans1 = y;
            a[i] = 0;
            break;
        }
    }
    all_xr = 0;
    for(int i = 0; i < n; ++i){
        all_xr ^= a[i];
    }
    int mask = all_xr - (all_xr & (all_xr - 1));
    for(int i = 0; i < n; ++i){
        if(a[i] & mask){
            ans2 ^= a[i];
        }
        else{
            ans3 ^= a[i];
        }
    }
    if(ans1 > ans2){
        int tmp = ans1;
        ans1 = ans2;
        ans2 = tmp;
    }
    if(ans1 > ans3){
        int tmp = ans1;
        ans1 = ans3;
        ans3 = tmp;
    }
    if(ans2 > ans3){
        int tmp = ans2;
        ans2 = ans3;
        ans3 = tmp;
    }
    printf("%d %d %d", ans1, ans2, ans3);
    return 0;
}

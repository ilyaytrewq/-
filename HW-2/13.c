#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int a[8], b[8];
    for(int i = 0; i < 8; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 8; ++i){
        scanf("%d", &b[i]);
    }
    int desk[8][8];
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            desk[i][j] = (a[i] < b[j] ? a[i] : b[j]);
        }
    }
    for(int i = 0; i < 8; ++i){
        int mx1 = 0;
        int mx2 = 0;
        for(int j = 0; j < 8; ++j){
            mx1 = (mx1 < desk[i][j] ? desk[i][j] : mx1);
            mx2 = (mx2 < desk[j][i] ? desk[j][i] : mx2);
        }
        if(mx1 != a[i] || mx2 != b[i]){
            printf("-1");
            return 0;
        }
    }
     int usedb[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int ans = 0;
    for(int i = 0; i < 8; ++i){
        int f = -1;
        for(int j = 0; j < 8; ++j){
            if(!usedb[j] && a[i] == b[j]){
                f = j;
                usedb[j] = 1;
                ans += a[i];
                break;
            }
        }
        if(f != -1){
            continue;
        }
        for(int j = 0; j < 8; ++j){
            if(a[i] <= b[j]){
                f = j;
                ans += a[i];
                break;
            }
        }
    }
    for(int j = 0; j < 8; ++j){
        if(usedb[j]){
            continue;
        }
        ans += b[j];
    }
    printf("%d", ans);
    return 0;
}

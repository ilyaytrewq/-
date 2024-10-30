#include <stdio.h>
#include <limits.h>

int main(void){
    int n;
    scanf("%d", &n);
    int mx = INT_MIN;
    int cnt = 0;
    //printf("%d\n", mx);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(x > mx){
            mx = x;
            cnt = 1;
        }
        else if(x == mx){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
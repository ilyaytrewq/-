#include <stdio.h>
#include <limits.h>

int main(void){
    int n;
    scanf("%d", &n);
    int prev_num = INT_MIN;
    int ans = 0;
    int cur_len = 0;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(x > prev_num){
            cur_len++;
        }else{
            cur_len = 1;
        }
        ans = (ans > cur_len ? ans : cur_len);
        prev_num = x;
    }
    printf("%d\n", ans);
    return 0;
}
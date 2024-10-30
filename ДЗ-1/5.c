#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ans;
    scanf("%d", &ans);
    int prev_num = -1;
    for(int i = 1;; ++i){
        int cur_num;
        scanf("%d", &cur_num);
        if(cur_num == 0){
            if(i % 2 == 0){
                ans += prev_num;
            }
            break;
        }
        if(i % 2 == 1){
            prev_num = cur_num;
        }
        else{
            ans += prev_num * cur_num;
        }
    }
    printf("%d\n", ans);
    return 0;
}

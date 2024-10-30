#include <stdio.h>

int main(void){
    int x;
    scanf("%x", &x);
    //printf("%d", x);
    int res = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            res += ((x >> (4 * i + j)) & 1) << (4 * j + i);
        }
    }
    printf("%04x", res);
    return 0;
}
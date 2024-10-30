#include <stdio.h>

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    x = (x < 0 ? -x : x);
    y = (y < 0 ? -y : y);
    if(x < y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    printf("%d\n", y * 2 + (x - y) / 2 * 3 + (x - y + 1) / 2);

    return 0;
}
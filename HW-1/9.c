#include <stdio.h>

int main(void) {
    unsigned int x;
    scanf("%u", &x);
    int ans = 0;
    while(x > 0){
        ans += x % 2;
        x /= 2;
    }
    printf("%d", ans);
    return 0;
}

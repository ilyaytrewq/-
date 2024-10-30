#include <stdio.h>
#include <limits.h>

int main(void){
    unsigned int n, k;
    scanf("%u %u", &n, &k);
    printf("%u", n & ((1 << k) - 1));
    return 0;
}
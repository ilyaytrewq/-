#include <stdio.h>

int main(void){
    unsigned int n;
    int k;
    scanf("%u%d", &n, &k);
    printf("%u", (n << (32 - k)) | (n >> k));
    return 0;
}
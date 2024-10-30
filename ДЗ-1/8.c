#include <stdio.h>

int getPartOfNum(unsigned int x, int l, int k){
    return ((x >> l) << (32 - k)) >> (32 - k);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for(int i = 0; i + k <= 32; ++i){
        int res = getPartOfNum(n, i, k);
        //printf("%d %d\n", i, res);
        ans = (ans > res ? ans : res);
    }
    printf("%d\n", ans);
    return 0;
}
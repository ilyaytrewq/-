#include <stdio.h>

int binpow(int a, int p, int mod){
    if(p == 0){
        return 1;
    }
    if(p % 2 == 1){
        return (a * binpow(a, p - 1, mod)) % mod;
    }
    int tmp = binpow(a, p / 2, mod);
    return (tmp * tmp) % mod;
}

int main(int argc, char const *argv[])
{
    int a, b, c, m;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    int arr[6][3] = { {a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a} };
    int ans = 0;
    for(int i =0 ; i < 6; ++i){
        int x = arr[i][0], y = arr[i][1], z = arr[i][2];
        int res = binpow(x, binpow(y, z, m), m);
        if(res > ans){
            ans = res;
        }
    }
    printf("%d", ans);
    return 0;
}

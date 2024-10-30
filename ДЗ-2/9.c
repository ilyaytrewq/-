#include <stdio.h>

long long f(long long *a, int n, long long x){
    long long ans = 0;
    long long cur_x = 1;
    for(int i = 0; i < n; ++i){
        ans += a[i] * cur_x;
        cur_x *= x;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    long long a[1000000];
    for(int i = 0; i < n; ++i){
        scanf("%lld", &a[i]);
    }
    int m;
    scanf("%d", &m);
    long long ans[1000000];
    for(int i = 0; i < m; ++i){
        long long x;
        scanf("%lld", &x);
        ans[m - i - 1] = f(a, n, x);
    }
    for(int i = 0; i < m; ++i){
        printf("%lld ", ans[i]);
    }
    
    return 0;
}

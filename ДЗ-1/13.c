#include <stdio.h>

double Pow(double x, int p){
    double ans = 1;
    for(int i = 0; i < p; ++i){
        ans *= x;
    }
    return ans;
}

long long factorial(long long n){
    long long ans = 1;
    for(long long i = 2; i <= n; ++i){
        ans *= i;
    }
    return ans;
}

int main(void){
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    double ans = 0;
    for(int i = 0; i < n; ++i){
        ans += Pow(-1, i) * Pow(x, 1 + i * 2) / factorial(1 + i * 2);
    }
    printf("%.6lf\n", ans);
    return 0;
}
#include <stdio.h>
#include <math.h>
#define eps 1e-6

int main(int argc, char const *argv[])
{
    double a, b, p, q;
    scanf("%lf%lf%lf%lf", &a, &b, &p, &q);
    if(a < b){
        double tmp = b;
        b = a;
        a = tmp;
    }
    if(p < q){
        double tmp = p;
        p = q;
        q = tmp;
    }
    double x = (a + b) / (p + q);
    double y = (a - b) / (p - q);
    if(p <= a && q <= b){
        printf("YES\n");
    }
    else if(p > a && q <= b && x * x + y * y - 2.0 >= -eps){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
    return 0;
}
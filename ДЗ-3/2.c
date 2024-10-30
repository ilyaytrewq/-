#include <stdio.h>

int isprime(int x){
    if(x < 2){
        return 0;
    }
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    while(isprime(n) == 0){
        n++;
    }
    printf("%d", n);
    return 0;
}

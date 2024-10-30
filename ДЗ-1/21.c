#include <stdio.h>
#define CountWeights 19

int Count(unsigned int a, unsigned int b){
    int pows[CountWeights];
    int used[CountWeights] = {0};
    pows[0] = 1;
    for(int i = 1; i < CountWeights; ++i){
        pows[i] = pows[i - 1] * 3;
    }
    int ans = 0;
    for(int i = CountWeights - 1; i >= 0; --i){
        if(a >= pows[i]){
            used[i] = 1;
            ans++;
            a -= pows[i];
        }   
    }
    for(int i = CountWeights - 1; i >= 0; --i){
        if(b >= pows[i] && used[i] == 0){
            ans++;
            b -= pows[i];
        }   
    }
    return (a == 0 && b == 0 ? ans : -1);
}

int main(void){
    unsigned int n;
    scanf("%d", &n);
    for(int i = n; i <= 1000 * 1000; ++i){
        int res = Count(i, i - n);
        if(res != -1){
            printf("%d\n", res);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
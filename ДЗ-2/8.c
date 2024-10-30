#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[4000];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }    
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 2; j < n; j += 2){
            if(a[(i + j) / 2] * 2 == a[i] + a[j]){
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

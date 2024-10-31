#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10001];
    int cnt = 0;
    while(1){
        int x;
        scanf("%d", &x);
        if(x == 0){
            break;
        }
        a[cnt++] = x;
    }
    for(int i = cnt - 1; i > -1; --i){
        printf("%d ", a[i]);
    }
    return 0;
}

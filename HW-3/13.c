#include <stdio.h>

void print(int *a, int maxnum, int prevnum, int step, int len){
    if(len == step){
        for(int i = 0; i < len; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = prevnum + 1; i < maxnum; ++i){
        a[step] = i;
        print(a, maxnum, i, step + 1, len);
        a[step] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);    
    int a[14];
    print(a, n, -1, 0, k);
    return 0;
}

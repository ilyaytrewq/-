#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int mx1 = INT_MIN;
    int mx2 = mx1, mx3 = mx1;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(x > mx1){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = x;
        }
        else if(x > mx2){
            mx3 = mx2;
            mx2 = x;
        }
        else if(x > mx3){
            mx3 = x;
        }
    }
    printf("%d %d %d", mx1, mx2, mx3);
    return 0;
}

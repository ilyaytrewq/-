#include <stdio.h>

void print(void){
    int x;
    scanf("%d", &x);
    if(x == 0){
        return;
    }
    print();
    printf("%d ", x);
}

int main(int argc, char const *argv[])
{
    print();
    return 0;
}

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    while(1){
        char c;
        scanf("%c", &c);
        if('a' <= c && c <= 'z'){
            c = (c - 'a' + n) % 26 + 'a'; 
        }
        else if('A' <= c && c <= 'Z'){
            c = (c - 'A' + n) % 26 + 'A';
        }
        printf("%c", c);
        if(c == '.')
            break;
    }
    return 0;
}
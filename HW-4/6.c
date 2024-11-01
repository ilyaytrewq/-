#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[1000005];
    int k;
    scanf("%d ", &k);
    int n = 0;
    char c;
    scanf("%c", &c);
    int spaces = 0;
    while(c != '\n'){
        s[n++] = c;
        if(c == ' '){
            spaces++;
        }
        scanf("%c", &c);
    }
    int addAll = (k - n) / spaces;
    int addFirst = (k - n) % spaces;
    for(int i = 0; i < n; ++i){
        printf("%c", s[i]);
        if(s[i] == ' '){
            int cntspaces = addAll + (addFirst-- > 0);
            for(int j = 0; j < cntspaces ; ++j){
                printf(" ");
            }
        }
    }
    return 0;
}

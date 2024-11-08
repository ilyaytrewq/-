#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

void calc(const char *s, int l, int r, int p, char *buf){
    for(int i = 0; i < 12; ++i){
        buf[i] = '\0';
    }
    strncpy(buf, s + l, p - l);
    ll num1 = atoll(buf);
    buf[0] = '\0';
    strncpy(buf, s + p + 1, r - p);
    ll num2 = atoll(buf);
    ll ans = 0;
    switch (s[p]) {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                return;
            }
            ans = num1 / num2;
        default:
            break;
    }
    if((ans < 0 ? -ans : ans) <= 120000){
        printf("%lld %c %lld = %lld\n", num1, s[p], num2, ans);
    }
}

inline int in(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(int argc, char const *argv[])
{
    char s[2005];
    char buf[15];
    scanf("%2000s", s);
    int n = strlen(s);  
    for(int i = 0; i < n; ++i){
        if(!isdigit(s[i])){
            continue;
        }
        int it = i;
        int posOp = -1;
        while(it < n && (isdigit(s[it]) || (posOp == -1 && in(s[it])))){
            if(!isdigit(s[it])){
                posOp = it;   
            }
            it++;
        }
        if(posOp != -1 && posOp != it - 1){
            calc(s, i, it, posOp, buf);
        }
        i = (posOp == -1 ? it - 1 : posOp);
    }
    return 0;
}

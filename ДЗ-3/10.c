#include <stdio.h>

int CalcPPN(char op) {
    char tmp;
    int x, y;
    scanf(" %c", &tmp);
    int sx = 1, sy = 1;
    if(tmp == '-'){
        sx = -1;
        scanf(" %c", &tmp);
    }
    if ('0' <= tmp && tmp <= '9') {
        x = 0;
        while (tmp != ' ' && tmp != '\n') {
            x *= 10;
            x += tmp - '0';
            scanf("%c", &tmp);
        }
    }
    else {
        x = CalcPPN(tmp);
    }
    scanf(" %c", &tmp);
    if(tmp == '-'){
        sy = -1;
        scanf(" %c", &tmp);
    }
    if ('0' <= tmp && tmp <= '9') {
        y = 0;
        while (tmp != ' ' && tmp != '\n') {
            y *= 10;
            y += tmp - '0';
            scanf("%c", &tmp);
        }
    }
    else {
        y = CalcPPN(tmp);
    }
    x *= sx;
    y *= sy;
    if (op == '*') {
        return x * y;
    }
    else {
        return x / y;
    }
}

int main(int argc, char const* argv[])
{
    char op;
    scanf("%c", &op);
    int s = 1;
    if(op == '-'){
        s = -1;
        scanf(" %c", &op);
    }
    if ('0' <= op && op <= '9') {
        int ans = 0;
        ans = 0;
        while (op != ' ' && op != '\n') {
            ans *= 10;
            ans += op - '0';
            scanf("%c", &op);
        }
        printf("%d", ans * s);
    }
    else {
        printf("%d", CalcPPN(op));
    }
    return 0;
}

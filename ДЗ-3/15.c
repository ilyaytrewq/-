#include <stdio.h>

int f(int step, int n) {
    if (step > n / 2) {
        return 1;
    }
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    int res = f(step + 1, n);
    if (step == 0 || step == n / 2) {
        return 1 & res;
    }
    int x2, y2;
    scanf("%d%d", &x2, &y2);
    if (x2 != -x1 || y2 != y1) {
        return 0;
    }
    return 1 & res;
}

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    if (f(0, n)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}

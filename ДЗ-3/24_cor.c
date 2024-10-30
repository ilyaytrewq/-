#include <stdio.h>

long long min (long long a, long long b) {
    return a < b ? a : b;
}
int lighten(int N) {
    long long right = 0, left_max = 0;
    int last = 0, last_illuminated = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        scanf ("%lld", &x);
        int now_illuminated = 0;
        if (right) {
            right--;
            left_max = i;
            ans++;
            now_illuminated = 1;
        }
        if (x < 0) {
            ans += min(i - left_max - 1, -x);
            if (now_illuminated)
                ans++;
            if (i + x <= last && last_illuminated == 0)
                ans++;
            right = 0;
            left_max = i;
            last = i;
            last_illuminated = now_illuminated;
        }
        if (x > 0) {
            right = x;
            left_max = i;
            last = i;
            last_illuminated = now_illuminated;
        }
    }
    return ans;
}

int main(void) {         
    int N;
    scanf("%d", &N);
    printf("%d", lighten(N));
    return 0;
}

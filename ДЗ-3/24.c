#include <stdio.h>

long long min(long long a, long long b) {
    return (a < b ? a : b);
}

long long lighten(long long n){
    long long prev_pos = -1, prev = -1, ans = 0, used = 0;
    for (long long i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        if (x == 0) {
            continue;
        }
        long long will_used = 0;
        if (x < 0) {
            if (prev < 0) {
                ans += min(i - prev_pos - 1, -x);
                if (i - prev_pos - 1 < -x && used == 0 && prev_pos != -1) {
                    ans++;
                }
            }
            else {
                long long cnt = i - prev_pos - 1;
                ans += min(cnt, prev - x);
                if (-x > cnt && used == 0) {
                    ans++;
                }
                if (prev > cnt) {
                    ans++;
                    will_used = 1;
                }
            }
        }
        else {
            if (prev > 0) {
                ans += min(i - prev_pos, prev);
                if (prev >= i - prev_pos) {
                    will_used = 1;
                }
            }
        }
        used = will_used;
        prev = x;
        prev_pos = i;
    }
    if (prev > 0) {
        ans += min(n - prev_pos - 1, prev);
    }
    return ans;
}

int main(int argc, char const* argv[])
{
    long long n;
    scanf("%lld", &n);
    printf("%lld", lighten(n));
    return 0;
}
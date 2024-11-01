#include <stdio.h>
#include <string.h>

void PrefixFunction(char *s, int n, int *pr){
    pr[0] = 0;
    for(int i = 1; i < n; ++i){
        int k = pr[i - 1];
        while (k && s[k] != s[i]){
            k = pr[k - 1];
        }
        pr[i] = k;
        if (s[i] == s[k])pr[i]++;
    }
}

int main(int argc, char const *argv[])
{
    char s1[10005];
    char s2[10005];
    char s[20005];
    int pr[20005];
    scanf("%10000s", s1);
    scanf("%10000s", s2);
    int n = strlen(s1);
    int m = strlen(s2);
    strcat(s, s1);
    strcat(s, "#");
    strcat(s, s2);
    PrefixFunction(s, n + m + 1, pr);
    int ans1 = pr[n + m];
    s[0] = '\0';
    strcat(s, s2);
    strcat(s, "#");
    strcat(s, s1);
    PrefixFunction(s, n + m + 1, pr);
    int ans2 = pr[n + m];
    printf("%d %d\n", ans1, ans2);
    return 0;
}

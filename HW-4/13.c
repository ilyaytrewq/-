#include <stdio.h>
#include <string.h>

int min(int a, int b){
    return (a < b ? a : b);
}

int max(int a, int b){
    return (a > b ? a : b);
}

char s[2000002];
int z[2000002];

void ZFunction(const char *s, int n, int *z){
    z[0] = 0;
    int l = 0;
    for(int i = 1; i < n; ++i){
        z[i] = max(0, min(z[i - l], l + z[l] - i));
        while(z[i] + i < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(l + z[l] < i + z[i]){
            l = i;
        }
    }
    z[0] = n;
}

int main(int argc, char const *argv[])
{
    scanf("%1000000s", s);
    int n = strlen(s);
    s[n] = '#';
    for(int i = 0; i < n; ++i){
        s[i + n + 1] = s[i];
    }
    s[2 * n + 1] = '\0';
    ZFunction(s, 2 * n + 1, z);
    for(int i = n + 2; i < 2 * n + 1; ++i){
        if(z[i] + i == 2 * n + 1){
            printf("%d ", i - n - 1);
        }
    }
    printf("%d", n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void *xmalloc(int size)
{
    void *mem = malloc(size);
    if (mem == 0)
    {
        printf("Error on malloc happened\n");
        exit(-1);
    }
    return mem;
}

char *readString(void)
{
    int size = 0, capacity = 2;
    char *s = xmalloc(capacity * sizeof(char));
    s[size++] = getchar();
    while (s[size - 1] != '\n')
    {
        if (size == capacity)
        {
            capacity *= 2;
            s = realloc(s, capacity * sizeof(char));
            if (s == 0)
            {
                printf("Error on realloc happened\n");
                exit(-1);
            }
        }
        s[size++] = getchar();
    }
    s[size - 1] = '\0';
    return s;
}

int cmp(const char *s1, const char *s2)
{
    int it = 0;
    while (s1[it] == s2[it])
    {
        ++it;
    }
    return (s1[it] == '\0' || (islower(s1[it]) && isupper(s2[it])) ||
            ((islower(s1[it]) == islower(s2[it])) && s1[it] < s2[it]));
}

void mergesort(char **a, int left, int right)
{
    if (right - left <= 1)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    char **tmp = xmalloc((right - left) * sizeof(char *));
    int it1 = left, it2 = mid;
    for (int i = 0; i < right - left; ++i)
    {
        if (it1 == mid)
        {
            tmp[i] = a[it2++];
        }
        else if (it2 == right)
        {
            tmp[i] = a[it1++];
        }
        else if (cmp(a[it1], a[it2]))
        {
            tmp[i] = a[it1++];
        }
        else
        {
            tmp[i] = a[it2++];
        }
    }
    for (int i = 0; i < right - left; ++i)
    {
        a[left + i] = tmp[i];
    }
    free(tmp);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    char **a = xmalloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i)
    {
        a[i] = readString();
    }
    mergesort(a, 0, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%s\n", a[i]);
        free(a[i]);
    }
    free(a);
    return 0;
}

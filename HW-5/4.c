#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int size = 0, capacity = 10;
    int *a = malloc(capacity * sizeof(int));
    if (a == 0)
    {
        printf("Error on malloc happened\n");
        exit(-1);
    }
    scanf("%d", &a[0]);
    size++;
    while (a[size - 1] != 0)
    {
        if (size == capacity)
        {
            capacity *= 2;
            a = realloc(a, capacity * sizeof(int));
            if (a == 0)
            {
                printf("Error on realloc happened\n");
                exit(-1);
            }
        }
        scanf("%d", &a[size++]);
    }
    
    int ans = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (a[i] < a[size - 2])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    free(a);
    return 0;
}

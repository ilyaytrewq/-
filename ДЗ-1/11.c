#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int n;
    scanf("%u", &n);
    printf("%u", n ^ (0xFF000000));
    return 0;
}

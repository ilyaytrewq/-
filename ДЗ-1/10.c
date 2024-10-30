#include <stdio.h>


int main(int argc, char const *argv[])
{
    unsigned char a, b, c, d;
    scanf("%hhu %hhu %hhu %hhu", &a, &b, &c, &d);
    printf("%u", (d << 24) | (c << 16) | (b << 8) | a);
    return 0;
}

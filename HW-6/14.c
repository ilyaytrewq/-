#include <stdio.h>
#include <stdlib.h>

int swap(int value)
{
    int converted = 0;
    converted |= ((0x000000ff & value) << 24);
    converted |= ((0x0000ff00 & value) << 8);
    converted |= ((0x00ff0000 & value) >> 8);
    converted |= ((0xff000000 & value) >> 24);
    return converted;
}

int main(int argc, char const *argv[])
{
    FILE *in = fopen("matrix.in", "rb"), *out = fopen("trace.out", "wb");
    if (in == NULL)
    {
        printf("NO FILE\n");
        return -1;
    }
    int n;
    fread(&n, 1, 2, in);
    n = ((n >> 8) | ((n & 0xff) << 8));
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x;
            fread(&x, 4, 1, in);
            ans += (i == j) * swap(x);
        }
    }
    char res[8] = {0};
    for (int i = 0; i < 8; ++i)
    {
        res[7 - i] = (ans & 0xFF);
        ans >>= 8;
    }
    fwrite(res, sizeof(char), 8, out);
    fclose(out);
    fclose(in);
    return 0;
}
#include <stdio.h>

int bit(int x, int p){
    return (x >> p) & 1;
}

int main(int argc, char const *argv[])
{
    unsigned int a11, a12, a21, a22, b1, b2, x = 0, y = 0;
    scanf("%u%u%u%u%u%u", &a11, &a12, &a21, &a22, &b1, &b2);
    
    for(int i = 0; i < 32; ++i){
        int x_bit = -1, y_bit = -1;
        for(int f = 0; f < 2; ++f){
            for(int s = 0; s < 2; ++s){
                if(((bit(a11, i) & f) ^ (bit(a12, i) & s)) == bit(b1, i) && 
                    ((bit(a21, i) & f) ^ (bit(a22, i) & s)) == bit(b2, i) &&
                    x_bit == -1 && y_bit == -1){
                        x_bit = f;
                        y_bit = s;
                    }
            }
        }
        if(x_bit == -1 || y_bit == -1){
            printf("No\n");
            return 0;
        }
        x |= (x_bit << i);
        y |= (y_bit << i);
    }
    printf("Yes\n%u %u", x, y);
    return 0;
}

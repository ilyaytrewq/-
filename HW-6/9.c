#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *in = fopen("input.bin", "rb"), *out = fopen("output.bin", "wb");
    if(in == NULL){
        printf("NO FILE\n");
        return -1;
    }

    /*int n;
    fread(&n, sizeof(int), 1, in);
    int *a = malloc(n * sizeof(int));
    fread(a,sizeof(int), n, in );
    */

    int size = 0, cap = 8;
    int *a = malloc(cap * sizeof(int));
    while(fread(a[size], sizeof(int), 1, in) == 1){
        size++;
        if(size == cap){
            cap *= 2;
            a = realloc(a, cap * sizeof(int));
        }
    } 

    if(size == 1){
        int f = 1;
        fwrite(&f, sizeof(int), 1, out);
        fclose(in);
        fclose(out);
        return 0;
    }
    int ok = 1;
    int f = -1;
    if (a[0] <= a[1]){
        f = 1;
        for(int i = 0; i < size; ++i){
            a[i] = -a[i];
        }
    }
    for(int i = 0; i < size; ++i){
        if(2 * i + 1 < size && a[i] < a[2 * i + 1]){
            ok = 0;
        }
        if(2 * i + 2 < size && a[i] < a[2 * i + 2]){
            ok = 0;
        }
    }
    if(!ok)
        f = 0;
    fwrite(&f, sizeof(int), 1, out);
    free(a);
    fclose(in);
    fclose(out);
    return 0;
}

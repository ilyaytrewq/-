#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");
    if(f == 0){
        printf("NO FILE\n");
        exit(-1);
    }
    int n, m;
    fscanf(f, "%d %d", &n, &m);
    int start = 0;
    for(int i = 0; i < m; ++i){
        int x;
        fscanf(f, "%d", &x);
        if(x == 0)
            continue;
        start = x;
    }
    fclose(f);
    f = fopen("output.txt", "w");
    for(int i = start; i <= n; ++i){
        fprintf(f, "%d ", i);
    }
    for(int i = 1; i < start; ++i){
        fprintf(f, "%d ", i);
    }
    fclose(f);
    return 0;
}

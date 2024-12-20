#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, xn, yn, xk, yk;
    scanf("%d %d %d %d %d", &n, &xn, &yn, &xk, &yk);
    --xn, --yn, --xk, --yk;
    int **q = malloc(n * n * sizeof(int *));
    int **d = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        d[i] = malloc(n * sizeof(int));
    }
    for(int i = 0; i < n * n; ++i){
        q[i] = malloc(2 * sizeof(int));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            d[i][j] = INT_MAX;
        }
    }
    d[xn][yn] = 0;
    int it = 0, size = 0;
    q[size][0] = xn;
    q[size][1] = yn;
    size++;
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    while (it < size)
    {
        int x = q[it][0];
        int y = q[it][1];
        ++it;
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n &&
                 d[nx][ny] > d[x][y] + 1)
            {
                d[nx][ny] = d[x][y] + 1;
                q[size][0] = nx;
                q[size][1] = ny;
                size++;
            }
        }
    }
    if (d[xk][yk] == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d", d[xk][yk]);
    }
    return 0;
}

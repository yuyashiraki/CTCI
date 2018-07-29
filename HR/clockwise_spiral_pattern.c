#include <stdio.h>

int main()
{
    int m = 4, n = 4;
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int i, x = 0, y = 0;
    while (x < n && y < m) {
        for (i = x; i < n; ++i) {
            printf("%d ", matrix[y][i]);
        }
        y++;
        for (i = y; i < m; i++) {
            printf("%d ", matrix[i][n - 1]);
        }
        n--;
        if (y < m) {
            for (i = n - 1; i >= x; --i) {
                printf("%d ", matrix[m - 1][i]);
            }
            m--;
        }
        if (x < n) {
            for (i = m - 1; i >= y; --i) {
                printf("%d ", matrix[i][x]);
            }
            x++;
        }
    }
}

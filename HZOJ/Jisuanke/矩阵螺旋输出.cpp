#include <stdio.h>
int cnt = 0, n, m;

void out() {
    cnt++;
    if (cnt == n * m)
        printf("\n");
    else
        printf(" ");
    return;
}

int main() {
    int matrix[100][100];
    int x[4] = {0, 1, 0, -1}, y[4] = {1, 0, -1, 0};
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int dir = 0, l = 0, i = 0, j = 0;
    while (cnt < n * m) {
        printf("%d", matrix[i][j]);
        if (x[dir] != 0) {
            if (i + x[dir] >= m - l || i + x[dir] <= l) {
                dir++;
            }
            if (dir == 4) {
                dir = 0;
                l++;
            }
        } else {
            if (j + y[dir] >= n - l || j + y[dir] < l) {
                dir++;
            }
        }
        // printf("I-%dJ-%d", i, j);
        i += x[dir];
        j += y[dir];
        out();
    }

    return 0;
}
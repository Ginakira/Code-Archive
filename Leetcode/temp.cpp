#include <stdio.h>

#define N 5
#define M 5

int grid[N][M]{{1, 7, -8, 10, -5},
               {-4, -9, 8, -6, 0},
               {5, -2, -6, -6, 7},
               {-7, 4, 7, -3, -3},
               {7, 1, -6, 4, -9}};

bool visited[N][M];

int maxPoints = 0;
int lastRow = 0, lastCol = 0;

int max(int a, int b) { return (a > b) ? a : b; }

void dfs(int row, int col, int currentPoints) {
    if (row < 0 || row >= N || col < 0 || col >= M || visited[row][col]) return;

    currentPoints += grid[row][col];
    visited[row][col] = true;

    if (col == M - 1) {
        if (currentPoints > maxPoints) {
            maxPoints = currentPoints;
            lastRow = row;
            lastCol = col;
        }
    }

    if (row == N - 1) {
        if (currentPoints > maxPoints) {
            maxPoints = currentPoints;
            lastRow = row;
            lastCol = col;
        }
    }

    dfs(row, col + 1, currentPoints);
    dfs(row + 1, col, currentPoints);

    visited[row][col] = false;
}

int Solution(int start_x, int start_y) {
    int n = N, m = M;
    if (start_x < 0 || start_x >= n || start_y < 0 || start_y >= m) {
        return -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    dfs(start_x, start_y, 0);
    printf("(%d,%d)->(%d,%d): Max=%d\n", start_x, start_y, lastRow, lastCol,
           maxPoints);
}

int main() {
    Solution(0, 3);
    Solution(1, 2);
    return 0;
}
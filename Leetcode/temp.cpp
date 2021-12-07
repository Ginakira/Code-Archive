/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/12/06 23:26:26
************************************************************/
#include <stdio.h>

#define MAX_N 200
#define MAX_M 200



int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int origin[MAX_N][MAX_M];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &origin[i][j]);
        }
    }

    // Transform
    int transformed[MAX_N][MAX_M];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transformed[i][j] = origin[j][i];
        }
        for (int j = 0; j < n / 2; ++j) {
            int temp = transformed[i][j];
            transformed[i][j] = transformed[i][n - j - 1];
            transformed[i][n - j - 1] = temp;
        }
    }

    // Output
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            j&& printf(" ");
            printf("%d", transformed[i][j]);
        }
        printf("\n");
    }
    return 0;
}
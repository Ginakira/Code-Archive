/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/02/17 17:42:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n = 3, m = 4;
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = 233;
        }
    }
    return 0;
}
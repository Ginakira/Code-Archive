#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int stu[33][33];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> stu[i][j];
        }
    }
    for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
        cout << stu[i][j] << endl;
    }
    return 0;
}
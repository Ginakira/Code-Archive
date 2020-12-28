/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/12/25 21:45:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int square_number[100] = {0};
    for (int i = 1; i <= 64; ++i) {
        square_number[i] = i * i;
    }
    long long sum = 0;
    for (int i = 1, n = 1; i <= 64; ++i) {
        while (sum < n * n + n) sum += square_number[i], ++n;
        if (sum == n * n + n) {
            cout << n << endl;
            break;
        }
        cout << sum << ' ' << n << endl;
    }
    return 0;
}
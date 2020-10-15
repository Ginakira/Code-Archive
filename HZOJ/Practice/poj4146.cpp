/************************************************************
    File Name : poj4146.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/30 11:38:50
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c, max_ans = -1;
    for (a = 0; a <= n; ++a) {
        for (b = 0; b <= n; ++b) {
            for (c = 0; c <= n; ++c) {
                if (((a + b) % 2 == 0) && ((b + c) % 3 == 0) &&
                    ((a + b + c) % 5 == 0)) {
                    max_ans = max(max_ans, a + b + c);
                }
            }
        }
    }
    cout << max_ans << endl;
    return 0;
}
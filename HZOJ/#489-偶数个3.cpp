/************************************************************
    File Name : #489-偶数个3.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/04 11:34:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000
int even[MAX_N + 5] = {0, 8}, odd[MAX_N + 5] = {0, 1};

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        odd[i] = odd[i - 1] * 9 + even[i - 1];
        even[i] = odd[i - 1] + 9 * even[i - 1];
        even[i] %= 12345;
        odd[i] %= 12345;
    }
    cout << even[n] << endl;
    return 0;
}
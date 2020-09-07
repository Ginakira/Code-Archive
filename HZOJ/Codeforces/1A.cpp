/************************************************************
    File Name : 1A.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/07 23:02:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    long long cols = n / a + (n % a ? 1 : 0);
    long long rows = m / a + (m % a ? 1 : 0);
    cout << rows * cols << endl;

    return 0;
}
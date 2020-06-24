/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/06/24 19:03:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(int n) {
    static int k = 1;
    k++;
    return 2 * n + k;
}

int main() {
    cout << f(3) << ' ' << f(f(3)) << endl;
    return 0;
}
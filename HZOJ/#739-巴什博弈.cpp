/************************************************************
    File Name : #739-巴什博弈.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/01/02 16:01:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, m;
        cin >> n >> m;
        cout << (n % (m + 1) ? "cong" : "ling") << endl;
    }
    return 0;
}
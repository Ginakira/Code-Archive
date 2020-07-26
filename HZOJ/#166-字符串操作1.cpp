/************************************************************
    File Name : #166-字符串操作1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/26 23:43:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str1, str2;
    int n;
    cin >> str1 >> n >> str2;
    cout << min(str1.length(), (size_t)100) << endl;
    str1.insert(n - 1, str2);
    cout << str1 << endl;
    cout << str1.length() - str1.rfind('x') << endl;
    return 0;
}
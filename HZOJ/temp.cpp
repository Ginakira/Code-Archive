/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/05 19:55:16
************************************************************/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void my_swap(bitset<32UL>::reference a, bitset<32UL>::reference b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main() {
    bitset<32> a(1418399120);

    cout << a << endl;
    for (int i = 0; i < 8; ++i) {
        my_swap(a[i], a[i + 16]);
        my_swap(a[i + 8], a[i + 24]);
    }
    string s = a.to_string();
    int cal = 0;
    for (int i = 31; i >= 0; --i) {
        cal += (s[i] - '0') * pow(2, 31 - i);
    }
    cout << cal << endl;
    cout << a << endl;
    cout << a.to_ullong();
    return 0;
}
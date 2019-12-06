/************************************************************
    File Name : #261-数据结构.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 20:19:36
************************************************************/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[1000000];

int main() {
    int n, x, k, index = 0, length = 0;
    string op;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "I") {
            cin >> x;
            for (int i = length; i > index; --i) {
                a[i] = a[i - 1];
            }
            a[index++] = x;
            length++;
        } else if (op == "D") {
            if (index == 0) continue;
            for (int i = index - 1; i < length; ++i) {
                a[i] = a[i + 1];
            }
            index--;
            length--;
        } else if (op == "L") {
            if (index > 0) index--;
        } else if (op == "R") {
            if (index < length) index++;
        } else if (op == "Q") {
            cin >> k;
            int max_s = a[0], sum = 0;
            for (int i = 0; i < k; ++i) {
                sum += a[i];
                max_s = max(max_s, sum);
            }
            cout << max_s << endl;
        }

        cout << "INDEX" << index << endl << "ARRAY = ";
        for (int i = 0; i < length; ++i) {
            cout << a[i] << (i == index - 1 ? "^ " : " ");
        }
        cout << endl;
    }
    return 0;
}
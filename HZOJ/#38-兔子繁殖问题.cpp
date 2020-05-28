/************************************************************
    File Name : #38-兔子繁殖问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 11:40:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100

struct BigInt : vector<int> {
    BigInt(int x) {
        push_back(x);
        normal();
    }

    BigInt operator+(const BigInt &b) {
        BigInt ret = *this;
        for (int i = 0; i < b.size(); ++i) {
            if (i < ret.size()) {
                ret[i] += b[i];
            } else {
                ret.push_back(b[i]);
            }
        }
        ret.normal();
        return ret;
    }

    void normal() {
        for (int i = 0; i < size(); ++i) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    BigInt a = 1, b = 1, c = 0;
    while (n--) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    return 0;
}
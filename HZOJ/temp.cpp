/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 12:09:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    BigInt a = 0, b = 1, c = 1, d = 1;
    for (int i = 2; i <= n; ++i) {
        a = b, b = c, c = d;
        d = a + b;
    }
    cout << a << endl;
    return 0;
}
/************************************************************
    File Name : #41-练习题2墙壁涂色_dp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/26 20:52:17
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000

struct BigInt : public vector<int> {
    BigInt(int x = 0) {
        push_back(x);
        normal();  // 处理进位
    }

    BigInt operator*(int x) {
        BigInt ret(*this);
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] *= x;
        }
        ret.normal();
        return ret;
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        for (int i = 0; i < a.size(); ++i) {
            if (i < ret.size())
                ret[i] += a[i];
            else
                ret.push_back(a[i]);
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

BigInt f[MAX_N + 5];
// f(n) 代表首尾颜色不一致的方案总数（就是所求答案）
// f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1)
// 前为第n - 1块与第一块颜色不一致的情况，后面是与第一块颜色一致的情况

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];
    }
    return out;
}

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);

    for (int i = 4; i <= n; ++i) {
        f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1);
    }

    cout << f[n] << endl;

    return 0;
}
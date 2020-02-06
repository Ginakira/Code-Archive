/************************************************************
    File Name : #565-位的交换.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/05 18:49:18
************************************************************/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bitset<32> ans;

void my_swap(bitset<32UL>::reference a, bitset<32UL>::reference b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main() {
    int n;
    cin >> n;
    ans = n;
    for (int i = 0; i < 8; ++i) {
        my_swap(ans[i], ans[i + 16]);
        my_swap(ans[i + 8], ans[i + 24]);
    }
    string s = ans.to_string();
    if (s[0] == '0') {
        cout << ans.to_ulong() << endl;
        return 0;
    }

    cout << "-";
    string one = "00000000000000000000000000000001";
    for (int i = 31; i > 0; --i) {
        if (s[i] < one[i]) {
            s[i - 1]--;
            s[i] += 2;
        }
        s[i] -= one[i] - '0';
    }
    for (int i = 0; i < 32; ++i) {
        if (s[i] == '0')
            s[i]++;
        else
            s[i]--;
    }
    bitset<32> neg(s);
    cout << neg.to_ulong() << endl;
    return 0;
}
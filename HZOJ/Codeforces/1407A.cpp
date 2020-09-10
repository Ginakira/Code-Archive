/************************************************************
    File Name : 1407A.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/08 23:09:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> &odd, vector<int> &even) {
    int n = odd.size() + even.size();
    int odd_cnt = 0, even_cnt = 0;
    vector<int> ans;
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            ans.push_back(odd[odd_cnt++]);
        } else {
            ans.push_back(even[even_cnt++]);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        i &&cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void adjust(vector<int> &v, int sum) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (sum <= 0) break;
        if (*it == 1) {
            v.erase(it);
            sum--;
        }
    }
    return;
}

void solve() {
    int n, odd_sum = 0, even_sum = 0;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        if (i % 2) {
            odd.push_back(temp);
            odd_sum += temp;
        } else {
            even.push_back(temp);
            even_sum += temp;
        }
    }
    if (odd_sum > even_sum) {
        cout << "ODD" << endl;
        adjust(odd, odd_sum - even_sum);
    } else if (even_sum > odd_sum) {
        cout << "EVEN" << endl;
        adjust(even, even_sum - odd_sum);
    }
    print(odd, even);
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
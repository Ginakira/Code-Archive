/************************************************************
    File Name : #245-货仓选址.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/17 19:20:34
************************************************************/

// 只要是右边的商店数量多 正向移动总会有正向收益
// 如果左边商店数量多 反向移动会有正向收益
// 最终将落在中点
// 实际是求S = \sigma{1~n} |Ai - pos| 的最优解
// 所以pos应该是序列A的中位数 一旦推出这个公式 pos一定是中位数

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int pos = a[n / 2];
    int sum = 0;
    for (int i : a) {
        sum += abs(i - pos);
    }
    cout << sum << endl;
    return 0;
}
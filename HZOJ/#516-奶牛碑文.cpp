/************************************************************
    File Name : #516-奶牛碑文.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/09 20:02:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    string s;
    cin >> n >> s;
    int cnt_c = 0, cnt_w = count(s.begin(), s.end(), 'W');
    for (auto i : s) {
        if (i == 'C')
            cnt_c++;
        else if (i == 'W')
            cnt_w--;
        else if (i == 'O') {
            ans += cnt_c * cnt_w;
        }
    }
    cout << ans << endl;
    return 0;
}
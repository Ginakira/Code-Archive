/*************************************************************************
	> File Name: P1003铺地毯.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月11日 星期四 21时42分02秒
 ************************************************************************/

#include<iostream>
using namespace std;
int g[10005][5];

int main() {
    int n, x, y;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 4; ++j)
            cin >> g[i][j];
    }
    cin >> x >> y;
    for(int k = n; k > 0; --k) {
        if(g[k][1] <= x && g[k][1] + g[k][3] >= x && g[k][2] <= y && g[k][2] + g[k][4] >= y) {
            cout << k << endl;
            return 0;
        }
        if(k == 1) cout << -1 << endl;
    }
    return 0;
}

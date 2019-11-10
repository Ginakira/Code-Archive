/*************************************************************************
	> File Name: P1031均分纸牌.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月18日 星期四 23时06分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int card[101] = {0}, n, ave = 0;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        cin >> card[i];
        ave += card[i];
    }
    ave /= n;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(card[i] == ave) continue;
        if(card[i] > ave) {
            card[i + 1] += card[i] - ave;
            card[i] = ave;
            ans++;
            continue;
        }
        else {
            card[i + 1] -= ave - card[i];
            card[i] = ave;
            ans++;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}

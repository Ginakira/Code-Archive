/*************************************************************************
	> File Name: P1067多项式输出.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月12日 星期五 22时15分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, num[150];
    bool flag = true;
    cin >> n;
    for(int i = 0; i <= n; ++i) cin >> num[i];
    if(num[0] == 0) flag = false;
    else if(num[0] == 1) cout << "x^" << n;
    else if(num[0] == -1) cout << "-x^" << n;
    else{
        cout << num[0] << "x^" << n;
    }
    for(int j = 1; j < n; ++j) {
        if(num[j] > 0 && flag) cout << '+';
        if(num[j] == 0) continue;
        if(num[j] == 1 || num[j] == -1) {
            if(num[j] == -1) {
                if(n - j == 1) {
                    cout << '-' << "x";
                    continue;
                }
                cout << '-' << "x^" << n - j;
                continue;
            }
            if(n - j == 1) {
                cout << "x";
                continue;
            }
            cout << "x^" << n - j;
            continue;
        }
        if(n - j == 1) {
            cout << num[j] << "x";
            continue;
        }
        cout << num[j] << "x^" << n - j;
    }
    if(num[n] > 0) {
        cout << '+' << num[n] << endl;
        return 0;
    }
    if(num[n] == 0) {
        return 0;
    }
    if(num[n] < 0) {
        cout << num[n] << endl;
        return 0;
    }
    return 0;
}

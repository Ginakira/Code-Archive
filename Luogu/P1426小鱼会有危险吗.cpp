/*************************************************************************
	> File Name: P1426小鱼会有危险吗.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月09日 星期二 08时02分25秒
 ************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int s, x, now = 0, n = 0;
    cin >> s >> x;
    while(now <= s + x) {
        int t = 7 * pow(0.98, n);
        if(now >= s - x && now <= s + x) {
            if(now + t <= s + x) {
                cout << "y" << endl;
                return 0;
            }
            else {
                cout << "n" << endl;
                return 0;
            }
        }
        else {
            now += t;
            n++;
        }
    }
    cout << "n" << endl;
    return 0;
}

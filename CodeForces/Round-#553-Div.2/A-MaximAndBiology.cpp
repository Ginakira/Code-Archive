/*************************************************************************
	> File Name: A-MaximAndBiology.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月18日 星期四 23时36分16秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n, ans = INT32_MAX;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i <= n - 4; ++i) {
        string tmp = s.substr(i, 4);
        int now = 0;
        if(tmp[0] != 'A') {
            if(tmp[0] <= 'M') now += tmp[0] - 'A';
            else now += 'Z' - tmp[0] + 1;
        }
        if(tmp[1] != 'C') {
            if(tmp[1] <= 'O') now += abs(tmp[1] - 'C');
            else now += 'Z' - tmp[1] + 3;
        }
        if(tmp[2] != 'T') {
            if(tmp[2] <= 'F' || tmp[2] > 'T') {
                if(tmp[2] <= 'F') now += tmp[2] - 'A' + 7;
                else now += tmp[2] - 'T';
            }
            else now += 'T' - tmp[2];
        }
        if(tmp[3] != 'G') {
            if(tmp[3] >= 'T') now += 'Z' - tmp[3] + 7;
            else now += abs(tmp[3] - 'G');
        }
        if(now < ans) ans = now;
    }
    cout << ans << endl;
    return 0;
}

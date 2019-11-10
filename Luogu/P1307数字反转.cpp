/*************************************************************************
	> File Name: P1307数字反转.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月10日 星期三 18时46分52秒
 ************************************************************************/
// luogu-judger-enable-o2
#include<iostream>
#include<cstring>
using namespace std;
int main() {
    char num[20];
    int end = 0;
    bool flag = true, pos = true;
    cin >> num;
    if(num[0] == '0') {
        cout << 0 << endl;
        return 0;
    }
    if(num[0] == '-') {
        end = 1;
        pos = false;
    }
    int len = strlen(num);
    if(!pos) cout << '-';
    for(int i = len - 1; i >= end; --i) {
        if(num[i] == '0' && flag) continue;
        flag = false;
        cout << num[i];
    }
    cout << endl;
    return 0;
}

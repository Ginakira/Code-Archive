/*************************************************************************
	> File Name: P1042乒乓球.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月19日 星期五 19时35分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
int log[62501];
char s;
int main() {
    int win = 0, lose = 0;
    for(int i = 0; cin >> s && s != 'E'; ++i) {
        if(s == 'W') log[i] = 1;
        else log[i] = 2;
    }
    //11 Point
    for(int i = 0; 1; ++i) {
        if(log[i] == 1) win++;
        if(log[i] == 2) lose++;
        if(log[i] == 0) {
            cout << win << ':' << lose << endl << endl;
            break;
        }
        if(win >= 11 || lose >= 11) {
            if(win - lose >= 2 || lose - win >= 2) {
                cout << win << ':' << lose << endl;
                win = 0;
                lose = 0;
            }
        }
    }
    win = 0;
    lose = 0;
    //22 Point
    for(int i = 0; 1; ++i) {
        if(log[i] == 1) win++;
        if(log[i] == 2) lose++;
        if(log[i] == 0) {
            cout << win << ':' << lose << endl << endl;
            break;
        }
        if(win >= 21 || lose >= 21) {
            if(win - lose >= 2 || lose - win >= 2) {
                cout << win << ':' << lose << endl;
                win = 0;
                lose = 0;
            }
        }
    }
    return 0;
}

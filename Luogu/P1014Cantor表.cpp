/*************************************************************************
	> File Name: P1014Cantor表.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月09日 星期二 19时22分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, line = 0, sum = 0;
    cin >> n;
    while(sum < n) { //计算第n项在第line条斜线上
        sum += ++line;
    }
    int pos = n - (sum - line); //计算第n项在当前线的第pos个位置
    if(line % 2 == 1) { //如果在奇数线上
        cout << line + 1 - pos << '/' << pos << endl;
        return 0;
    }
    if(line % 2 == 0) { //如果在偶数行
        cout << pos << '/' << line + 1 - pos << endl;
        return 0;
    }
    return 0;
}

/*************************************************************************
	> File Name: P1328生活大爆炸版石头剪刀布.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月14日 星期日 20时43分02秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

queue<int> a;
queue<int> b;
int sa = 0, sb = 0;

void battle(int a, int b) {
    if(a == b) return ;
    if(a == 0) {
        if(b == 2 || b == 3) sa++;
        else sb++;
        return ;
    }
    if(a == 1) {
        if(b == 0 || b == 3) sa++;
        else sb++;
        return ;
    }
    if(a == 2) {
        if(b == 1 || b == 4) sa++;
        else sb++;
        return ;
    }
    if(a == 3) {
        if(b == 2 || b == 4) sa++;
        else sb++;
        return ;
    }
    if(a == 4) {
        if(b == 0 || b == 1) sa++;
        else sb++;
        return ;
    }
}

int main() {
    int n, na, nb;
    cin >> n >> na >> nb;
    for(int i = 0; i < na; ++i) {
        int t;
        cin >> t;
        a.push(t);
    }
    for(int i = 0; i < nb; ++i) {
        int t;
        cin >> t;
        b.push(t);
    }
    for(int cnt = 1; cnt <= n; ++cnt) {
        int aout = a.front();
        int bout = b.front();
        battle(aout, bout);
        
        //cout << "sa:" << sa << " sb:" << sb << endl;
        a.push(aout);
        b.push(bout);
        a.pop();
        b.pop();
    }
    cout << sa << ' ' << sb << endl;
    return 0;
}

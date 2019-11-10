#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int num[100010];

struct Call {
    int num, order, ans;
};

Call call[100010];

bool cmp1(Call a, Call b) {
    return a.num < b.num;
}

bool cmp2(Call a, Call b) {
    return a.order < b.order;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> call[i].num;
        call[i].order = i;
    }
    sort(call, call + m, cmp1);
    int ind = 0;
    for(int i = 0; i < m; ++i) {
        bool flag = false;
        while(num[ind] <= call[i].num && ind < n) {
            ind++;
            flag = true;
        }
        //cout << "INDEX" << ind  << ' ' << flag << endl;
        if(flag) call[i].ans = num[ind - 1], ind--;
        else call[i].ans = num[ind];
    }
    sort(call, call + m, cmp2);
    for(int i = 0; i < m; ++i) {
        if(i != 0) cout << ' ';
        cout << call[i].ans;
    }
    return 0;
}
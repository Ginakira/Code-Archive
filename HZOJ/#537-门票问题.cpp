/************************************************************
    File Name : #537-门票问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 20:43:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int l, c, cnt, fu, yuan, out_cnt;
char letters[30], ans[30];

int dfs(int s, int left) {
    if (!left) {
        if (yuan >= 1 && fu >= 2) {
            for (int i = 0; i < cnt; ++i) {
                cout << ans[i];
            }
            cout << endl;
            if (++out_cnt == 25000) return -1;
        }
        return 0;
    }
    for (int i = s; i < c; ++i) {
        ans[cnt++] = letters[i];
        bool flag = false;
        if (letters[i] == 'a' || letters[i] == 'e' || letters[i] == 'i' ||
            letters[i] == 'o' || letters[i] == 'u') {
            yuan++, flag = true;
        } else {
            fu++;
        }
        if (dfs(i + 1, left - 1) == -1) return -1;
        if (flag) {
            yuan--;
        } else {
            fu--;
        }
        cnt--;
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        cin >> letters[i];
    }
    sort(letters, letters + c);
    dfs(0, l);
    return 0;
}
/************************************************************
    File Name : #376-机器翻译.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 18:12:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

deque<int> mem;

int m, n, word, ans = 0;

bool search_mem(int target) {
    for (deque<int>::iterator it = mem.begin(); it != mem.end(); ++it) {
        if (*it == target) return true;
    }
    return false;
}

void add_mem(int word) {
    if (mem.size() < m) {
        mem.push_back(word);
        return;
    }
    mem.pop_front();
    mem.push_back(word);
    return;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        if (search_mem(word)) continue;
        add_mem(word);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
/************************************************************
    File Name : #534-体积.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/15 22:50:57
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
unordered_set<int> volume;
int n, num[25], sum;

void dfs(int s) {
    for (int i = s; i < n; ++i) {
        sum += num[i], volume.insert(sum);
        dfs(i + 1);
        sum -= num[i];
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    dfs(0);
    cout << volume.size() << endl;
    return 0;
}
/************************************************************
    File Name : #328-楼兰图腾.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/24 15:58:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 200000
#define lowbit(x) ((x) & (-x))
// rise 前面小的 fall 前面大的
int rise[MAX_N + 5], fall[MAX_N + 5];
int pre_sm[MAX_N + 5], pre_lg[MAX_N + 5];  // 某一位前面比它小的 前面比它大的
int suf_sm[MAX_N + 5], suf_lg[MAX_N + 5];  // 后面比它小的 后面比它大的
int a[MAX_N + 5];

void add(int *c, int i, int val, int n) {
    while (i <= n) c[i] += val, i += lowbit(i);
    return;
}

int query(int *c, int i) {
    int sum = 0;
    while (i) sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    
    return 0;
}
/************************************************************
    File Name : #248-逆序对个数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/26 15:54:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 500000
int arr[MAX_N + 5];
int temp[MAX_N + 5];
int n;

LL merge_sort(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) >> 1;
    LL ans1 = merge_sort(l, mid);
    LL ans2 = merge_sort(mid + 1, r);
    LL ans3 = 0;
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            ans3 += mid - p1 + 1;
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i <= r; ++i) arr[i] = temp[i - l];
    return ans1 + ans2 + ans3;
}

int solve() {
    cin >> n;
    if (n == 0) return n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    cout << merge_sort(1, n) << endl;
    return 1;
}

int main() {
    while (solve())
        ;
    return 0;
}
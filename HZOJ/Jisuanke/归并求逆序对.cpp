/************************************************************
    File Name : 归并求逆序对.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/23 19:56:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int merge_sort(int *num, int n) {  // 返回值为逆序对数量
    if (n <= 1) return 0;
    int ans = 0, mid = n / 2;
    ans += merge_sort(num, mid);
    ans += merge_sort(num + mid, n - mid);
    int *temp = (int *)malloc(sizeof(int) * n);
    int p1 = 0, p2 = mid, k = 0;
    while (p1 < mid || p2 < n) {
        if (p2 == n || (p1 < mid && num[p1] < num[p2])) {
            temp[k++] = num[p1++];
        } else {
            ans += mid - p1;
            temp[k++] = num[p2++];
        }
    }
    for (int i = 0; i < k; ++i) num[i] = temp[i];
    return ans;
}

int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << merge_sort(a, n) << endl;
    return 0;
}
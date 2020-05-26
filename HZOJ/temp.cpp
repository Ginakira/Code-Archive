/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/26 21:55:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    // Minimum
    for (int i = 1; i <= n; ++i) {
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (i < k) continue;
        if (i - q[head] >= k) head++;
        i == k || cout << ' ';
        cout << arr[q[head]];
    }
    cout << endl;
    // Maximum
    head = 0, tail = 0;
    for (int i = 1; i <= n; ++i) {
        while (tail - head && arr[q[tail - 1]] <= arr[i]) tail--;
        q[tail++] = i;
        if (i < k) continue;
        if (i - q[head] >= k) head++;
        i == k || cout << ' ';
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
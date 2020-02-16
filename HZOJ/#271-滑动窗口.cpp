/************************************************************
    File Name : WA#271-滑动窗口.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/15 12:28:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAXN 300000

int arr[MAXN];
int q[MAXN], head, tail;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    head = 0, tail = 0;
    for (int i = 0; i < n; ++i) {
        while (tail - head && arr[i] < arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if (i + 1 < k) continue;
        if (i - q[head] == k) head++;
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    head = 0, tail = 0;
    for (int i = 0; i < n; ++i) {
        while (tail - head && arr[i] > arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if (i + 1 < k) continue;
        if (i - q[head] == k) head++;
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
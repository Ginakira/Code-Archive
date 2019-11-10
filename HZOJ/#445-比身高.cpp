#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n;++i) {
        int front = 0, behind = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i]) front++;
        }
        for (int k = i + 1; k < n; ++k) {
            if (behind > front) break;
            if (a[k] > a[i]) behind++;
        }
        if (front == behind) cnt++;
    }
    cout << cnt;
    return 0;
}
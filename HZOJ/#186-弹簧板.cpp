#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[100010];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pos = 0;
    while(pos < n) {
        pos += a[pos];
        cnt++;
    }
    cout << cnt--;
    return 0;
}
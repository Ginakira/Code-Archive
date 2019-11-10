#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int x, cnt = 0;

void cal(int n) {
    while (n) {
        if(n % 10 == x) cnt++;
        n /= 10;
    }
    return;
}

int main() {
    int n;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cal(i);
    }
    cout << cnt;
    return 0;
}
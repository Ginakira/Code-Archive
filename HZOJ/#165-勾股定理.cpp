#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool mark[1000000] = {false};

int main() {
    long long c;
    int cnt = 0;
    cin >> c;
    for (long long a = 1; a < c; ++a) {
        long long b = sqrt(c * c - a * a);
        if (a + b <= c) continue;
        if (a * a + b * b == c * c && !mark[a] && !mark[b]) {
            mark[a] = mark[b] = true;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
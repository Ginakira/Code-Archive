#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long long cnt[70], cost[70];

void init() { for (int i = 3; i < 70; ++i) {
        cnt[i] = 2 * cnt[i - 1] + 1;
        cost[i] = cost[i - 1] * 2 + i;
    }
}

int main() {
    int n;
    cin >> n;
    cnt[1] = 1, cnt[2] = 3;
    cost[1] = 1, cost[2] = 4;
    init();
    cout << cnt[n] << ' ' << cost[n];
    return 0;
}

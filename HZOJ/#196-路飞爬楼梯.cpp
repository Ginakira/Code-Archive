#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int ans[55] = {0, 0, 1, 1, 1, 2};

void init() {
    for(int i = 6; i <= 50; ++i) {
        ans[i] = ans[i - 2] + ans[i - 3];
    }
    return;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << ans[n];
    return 0;
}
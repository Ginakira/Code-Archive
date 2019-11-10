#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    n--;
    while (n--) {
        ans = (ans + 1) * 2;
    }
    cout << ans;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, ans = 0;
    string n;
    cin >> x >> n;
    for (int i = 0; i < n.length(); ++i) {
        ans += (n[i] - '0') * pow(x, n.length() - i - 1);
    }
    cout << ans << endl;
    return 0;
}
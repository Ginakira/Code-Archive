#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int ans = 0;
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); ++i) {
        ans += n[i] - '0';
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string out, behind;
    string c = "A";
    char cn;
    int n;
    cin >> cn;
    n = cn - 'A' + 1;
    n--;
    for (int i = 0; i < n + 1; ++i) {
        out += c;
        c[0]++;
    }
    behind = out.substr(0, n + 1);
    reverse(behind.begin(), behind.end());
    out = behind + out;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << ' ';
        }
        for (int j = i, k = 0; k < 2 * n + 1 - 2 * i; ++j, ++k) {
            cout << out[j];
        }
        cout << endl;
    }
    return 0;
}
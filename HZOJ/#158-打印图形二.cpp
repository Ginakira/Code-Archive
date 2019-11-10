#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string out, behind;
    string c = "0";
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        out += c;
        c[0]++;
    }
    behind = out.substr(1, n);
    reverse(behind.begin(), behind.end());
    out = behind + out;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << ' ';
        }
        for (int j = i, k = 0; k < 2 * n + 1 - 2 * i; ++j, ++k) {
            if(k == 0 || k == 2 * n - 2 * i) cout << out[j];
            else
                cout << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << ' ';
        }
        for (int j = n - i, k = 0; k < 2 * i + 1; ++j, ++k) {
            if(k == 0 || k == 2 * i) cout << out[j];
            else
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
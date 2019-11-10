#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= (2 * n - 1) / 2; ++i) {
        for (int j = 0; j < (2 * n - i * 2) / 2; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < i * 2; ++j) {
            cout << 'A';
        }
        cout << endl;
    }
    for (int i = 0; i < (2 * n + 1) / 2; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * n - i * 2; ++j) {
            cout << 'A';
        }
        cout << endl;
    }
    return 0;
}
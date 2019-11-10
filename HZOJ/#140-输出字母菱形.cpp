#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char c = 'A';
    cin >> n;
    for (int i = 1; i <= (2 * n - 1) / 2; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            cout << c;
        }
        cout << endl;
        c++;
    }
    for (int i = 0; i < (2 * n + 1) / 2; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * n - 1 - 2 * i; ++j) {
            cout << c;
        }
        cout << endl;
        c--;
    }
    return 0;
}
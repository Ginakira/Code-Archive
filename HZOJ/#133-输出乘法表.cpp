#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (j != i) cout << "\t";
            cout << i << '*' << j << '=' << i * j;
        }
        cout << endl;
    }
    return 0;
}
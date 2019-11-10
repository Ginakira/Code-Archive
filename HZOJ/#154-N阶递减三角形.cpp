#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        bool first = true;
        for (int j = n - i; j > 0; --j) {
            if (first) first = false;
            else
                cout << " ";
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
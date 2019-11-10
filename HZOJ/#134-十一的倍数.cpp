#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    bool first = true;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % 11 == 0) {
            if (first) first = false;
            else
                cout << ' ';
            cout << i;
        }
    }
        return 0;
}
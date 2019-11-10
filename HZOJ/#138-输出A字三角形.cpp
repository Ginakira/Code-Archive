#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n * 2; i > 0; i -= 2) {
        for (int j = 0; j < i; ++j) {
            cout << 'A';
        }
        cout << endl;
    }
    return 0;
}
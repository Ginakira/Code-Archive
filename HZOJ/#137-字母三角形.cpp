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
    for (int i = n; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            cout << c++;
        }
        cout << endl;
    }
    return 0;
}
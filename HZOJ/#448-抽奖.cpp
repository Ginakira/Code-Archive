#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int prize[110];

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> prize[i];
    }
    cin >> num;
    for (int i = 0; i < n; ++i) {
        if(num == prize[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
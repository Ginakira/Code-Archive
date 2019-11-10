#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int height[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    sort(height, height + n);
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << height[i];
    }
    return 0;
}
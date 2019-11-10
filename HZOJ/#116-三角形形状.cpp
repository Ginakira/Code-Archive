#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2]) {
        cout << "illegal triangle\n";
    } else {
        if (a[0] * a[0] + a[1] * a[1] > a[2] * a[2]) {
            cout << "acute triangle\n";
        } else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
            cout << "right triangle\n";
        } else {
            cout << "obtuse triangle\n";
        }
    }
    return 0;
}
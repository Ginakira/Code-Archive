#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if(x == y) {
        cout << 100;
    } else if((x % 10 == y / 10) && (x / 10 == y % 10)) {
        cout << 20;
    } else if((x % 10 == y / 10) || (x / 10 == y % 10) || (x % 10 == y % 10) || (x / 10 == y / 10)) {
        cout << 2;
    } else {
        cout << 0;
    }
    return 0;
}
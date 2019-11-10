#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    if(a == b) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
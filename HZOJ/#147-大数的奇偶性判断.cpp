#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if((s[s.length() - 1] - '0') % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
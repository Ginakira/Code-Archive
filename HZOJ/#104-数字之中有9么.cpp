#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '9') {
            cout << "YES";
            return 0;
        }
    }
        cout << "NO";
        return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, string> mp;

int main() {
    mp['h'] = "He";
    mp['l'] = "Li";
    mp['c'] = "Cao";
    mp['d'] = "Duan";
    mp['w'] = "Wang";
    char c;
    cin >> c;
    if (mp[c] != "") {
        cout << mp[c];
    } else {
        cout << "Not Here";
    }
    return 0;
}
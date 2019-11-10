#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, add;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        cout << s << endl;
        add = s.substr(s.length() - 2, 2);
        s.erase(s.length() - 2, 2);
        s = add + s;
    }
    return 0;
}
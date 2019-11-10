#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int l = 110, r = -1;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            l = min(i, l);
            r = max(i, r);
        }
    }
    cout << r - l << endl;
    return 0;
}
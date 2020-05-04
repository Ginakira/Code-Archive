#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ch = 0, num = 0, space = 0, other = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i]))
            num++;
        else if (isalpha(s[i]))
            ch++;
        else if (isblank(s[i]))
            space++;
        else
            other++;
    }
    cout << ch << ' ' << num << ' ' << space << ' ' << other;
    return 0;
}
#include <algorithm>
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
        if (s[i] >= '0' && s[i] <= '9')
            num++;
        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            ch++;
        else if (s[i] == ' ')
            space++;
        else
            other++;
    }
    cout << ch << ' ' << num << ' ' << space << ' ' << other;
    return 0;
}
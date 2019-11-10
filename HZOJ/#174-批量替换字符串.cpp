#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    size_t pos;
    pos = s.find(" ");
    while(pos != s.npos) {
        s.replace(pos, 1, "%20");
        pos = s.find(" ");
    }
    cout << s << endl;
    return 0;
}
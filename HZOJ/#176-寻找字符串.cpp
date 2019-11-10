#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int cnt = 0;
    size_t pos;
    pos = a.find(b);
    while(pos != a.npos) {
        cnt++;
        a.erase(pos, 1);
        pos = a.find(b);
    }
    cout << cnt << endl;
    return 0;
}
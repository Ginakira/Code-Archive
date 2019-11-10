#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string tmp, s[110];
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        s[i] = tmp.substr(3, tmp.length() - 3);
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}
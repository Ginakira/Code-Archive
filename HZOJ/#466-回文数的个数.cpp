#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool is_palidrome(int a) {
    string s = to_string(a), tmp;
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(s == tmp) return true;
    else return false;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (is_palidrome(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
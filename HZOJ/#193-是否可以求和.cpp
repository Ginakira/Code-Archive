#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[100010];

int main() {
    int n, k, s;
    bool solved = false;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k >> s;
    for(int i = 0; i < n; ++i) {
        if(a[i] + k == s) {
            solved = true;
            break;
        }
    }
    if(solved) cout << "Yes";
    else cout << "No";
    return 0;
}
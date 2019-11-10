#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long long a[100010];

int main() {
    long long n, s;
    bool solved = false;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> s;
    int l = 0, r = 1;
    while(l < n - 1) {
        if(a[l] + a[r] == s) {
            solved = true;
            break;
        }
        if(a[l] + a[r] < s) r++;
        else {
            l++;
            r  = l + 1;
        }
    }
    if(solved) cout << "Yes";
    else cout << "No";
    return 0;
}
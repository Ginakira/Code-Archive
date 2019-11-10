#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long ans = 1;
    int n, tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        ans *= tmp;
    }
    cout << ans << endl;
    return 0;
}
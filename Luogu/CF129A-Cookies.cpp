#include <iostream>
using namespace std;

int main() {
    int odd = 0, even = 0, tmp, n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp % 2 == 0) ++even;
        else ++odd;
        sum += tmp;
    }
    if(sum % 2 == 0) cout << even;
    else cout << odd;
    return 0;
}
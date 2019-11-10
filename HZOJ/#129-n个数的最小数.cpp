#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, tmp, mina = 10010;
    cin >> n;
    while(n--) {
        cin >> tmp;
        mina = min(mina, tmp);
    }
    cout << mina << endl;
    return 0;
}
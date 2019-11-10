#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, tmp, maxa = -1, mina = 0x3f3f3f3f;
    cin >> n;
    while (n--) {
        cin >> tmp;
        maxa = max(maxa, tmp);
        mina = min(mina, tmp);
    }
    cout << maxa - mina << endl;
    return 0;
}
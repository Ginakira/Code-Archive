#include <iostream>
using namespace std;

int main() {
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int needp = n % s == 0 ? n / s : n / s + 1;
    needp *= k;
    needp = needp % p == 0 ? needp / p : needp / p + 1;
    cout << needp;
    return 0;
}
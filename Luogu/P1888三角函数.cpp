#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int Gcd1(unsigned int a, unsigned int b) {
    if (a % b != 0) {
        if (a > b) Gcd1(b, a % b);
    }
    else if (a % b == 0)
    return b;
}
int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int max = Gcd1(a[2], a[0]);
    cout << a[0] / max << '/' << a[2] / max << endl;
    return 0;
}
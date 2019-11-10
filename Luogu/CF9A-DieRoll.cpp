#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int y, w;
    cin >> y >> w;
    int a;
    a = 6 - max(y, w) + 1;
    cout << a / __gcd(6, a) << '/' << 6 / __gcd(6, a);
    return 0;
}
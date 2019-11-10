#include <iostream>
using namespace std;

int main() {
    int x, a, b;
    cin >> x;
    for (int a = 1; a <= x; ++a) {
        for (int b = 1; b <= x; ++b) {
            if (a % b != 0) continue;
            else if(a * b > x && a / b < x) {
                cout << a << ' ' << b;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
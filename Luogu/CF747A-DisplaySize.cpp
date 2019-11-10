#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a = 0, b = 0, tmp;
    cin >> n;
    tmp = round(sqrt(n));
    for (int i = tmp; i > 0; --i) {
        if(n % i == 0) {
            a = i;
            b = n / i;
            break;
        }
    }
    cout << a << ' ' << b;
    return 0;
}
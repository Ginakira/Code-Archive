#include <iostream>
using namespace std;

int fac(int n) {
    int sum = 0;
    for(int i = 1; i < n; ++i) {
        if(n % i == 0) sum += i;
    }
    return sum;
}

int main() {
    int n, a, b;
    cin >> n;
    for(int i = n; ; ++i) {
        a = fac(i);
        if(fac(a) == i) {
            b = i;
            if(a == b) {
                continue;
            }
            break;
        }
    }
    cout << b << ' ' << a << endl;
    return 0;
}
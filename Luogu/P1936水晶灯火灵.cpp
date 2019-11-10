#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

int fib[1001];
int main() {
    int k;
    cin >> k;
    int i;
    fib[1] = 1, fib[2] = 1;
    for(i = 3; fib[i - 1] + fib[i] <= k; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << "m=" << fib[i - 3] << endl;
    cout << "n=" << fib[i - 2] << endl;
    return 0;
}
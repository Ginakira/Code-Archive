#include <iostream>
using namespace std;

int main() {
    long long n, m, a, n1, n2;
    cin >> n >> m >> a;
    n1 = n % a == 0 ? n / a : n / a + 1;
    n2 = m % a == 0 ? m / a : m / a + 1;
    cout << n1 * n2 << endl;
    return 0;
}
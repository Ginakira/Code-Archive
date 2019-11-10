#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long tmp = pow(2, n);
    cout << m % tmp;
    return 0;
}
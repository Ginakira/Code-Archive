#include <iostream>
using namespace std;
int main() {
    long long x, n, sum = 1;
    cin >> x >> n;
    for(int i = 0; i < n; ++i) {
        sum += sum * x;
    }
    cout << sum << endl;
    return 0;
}
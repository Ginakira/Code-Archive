#include <iostream>
using namespace std;

bool isp(int n) {
    if (n == 2)
        return true;
    else if (n == 1 || n == 0)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (isp(n))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
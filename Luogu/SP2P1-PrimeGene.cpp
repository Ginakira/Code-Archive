#include <iostream>
using namespace std;

bool isprime(int n) {
    if(n == 1 || n == 0)
        return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = n; i <= m; ++i) {
            if(isprime(i))
                cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}
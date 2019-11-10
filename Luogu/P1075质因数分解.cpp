#include <iostream>
using namespace std;

bool is_prime(int n) {
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i < n; ++i) {
        if(!is_prime(i)) continue;
        if(n % i != 0) continue;
        int t = n / i;
        if(is_prime(i) && is_prime(t)) {
            cout << t << endl;
            return 0;
        }
    }
    return 0;
}
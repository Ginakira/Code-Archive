#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    n *= 2;
    for(int i = 0; i <= n; ++i) {
        if(i * i + i == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
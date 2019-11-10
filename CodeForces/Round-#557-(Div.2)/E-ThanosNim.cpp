#include <iostream>
using namespace std;

int main() {
    int n, one = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if(t != 1) one++;
    }
    if(one / (n / 2) % 2 == 0) cout << "Bob\n";
    else cout << "Alice\n";

    return 0;
}
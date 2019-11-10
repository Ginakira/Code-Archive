#include <iostream>
using namespace std;

int main() {
    int k, n, m;
    cin >> k;
    while(k--) {
        cin >> n >> m;
        cout << min(n, m) * 2 - 2 << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    string a, b;
    int l, r;
    cin >> a >> b;
    for(l = 0, r = b.length() - 1; r >= 0; ++l, --r) {
        if(a[l] != b[r]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string t;
        cin >> t;
        if((t[t.length() - 1] - '0') % 2 == 0) cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}
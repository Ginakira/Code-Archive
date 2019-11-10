#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        if(t % 2 == 0) cout << "pb wins\n";
        else cout << "zs wins\n";
    }
    return 0;
}
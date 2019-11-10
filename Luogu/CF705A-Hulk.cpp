#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        if(i % 2 == 1) cout << "I love that ";
        else cout << "I hate that ";
    }
    if(n % 2 == 0) cout << "I love it";
    else cout << "I hate it";
    return 0;
}
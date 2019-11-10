#include <iostream>
using namespace std;

int main() {
    int n, tmp, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
    }
    if(sum % 2 == 0) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}
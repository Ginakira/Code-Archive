#include <iostream>
#include <string>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a += c, b += c;
    if(a == b) cout << a * 2 << endl;
    else cout << min(a, b) * 2 + 1 << endl;
    return 0;
}
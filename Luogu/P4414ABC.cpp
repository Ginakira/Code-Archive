#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    string s;
    cin >> s;
    for(int i = 0; i < 2; ++i) {
        cout << a[s[i] - 'A'] << ' ';
    }
    cout << a[s[2] - 'A'] << endl;
    return 0;
}
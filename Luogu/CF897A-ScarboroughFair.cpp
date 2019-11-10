#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n, m, l, r;
    char c1, c2;
    cin >> n >> m >> s;
    while(m--) {
        cin >> l >> r >> c1 >> c2;
        for(int i = l - 1; i <= r - 1; ++i) {
            if(s[i] == c1) s[i] = c2;
        }
    }
    cout << s;
    return 0;
}
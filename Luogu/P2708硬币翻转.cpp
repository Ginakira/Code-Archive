#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length(), ans = 0;
    for(int i = 0; i < len - 1; ++i) {
        if(s[i] != s[i + 1]) ans++;
    }
    if(s[len - 1] == '0') ans++;
    cout << ans << endl;
    return 0;
}
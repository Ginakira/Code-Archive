#include <iostream>
using namespace std;

int main() {
    string s;
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0, ans = 0;
        cin >> s;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'X') cnt = 0;
            else ans += ++cnt;
        }
        cout << ans << endl;
    }
    return 0;
}
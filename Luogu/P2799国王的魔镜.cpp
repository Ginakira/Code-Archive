#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s, tmp, tmp2;
    int ans = 0, len;
    bool fail = false;
    cin >> s;
    if(s.length() % 2 != 0) {
        cout << s.length() << endl;
        return 0;
    }
    ans = s.length();
    while(!fail) {
        if(s.length() % 2 != 0) {
        cout << ans << endl;
        return 0;
    }
        len = s.length() / 2;
        if(s[len] == s[len - 1]) {
            tmp = s.substr(0, len);
            tmp2 = s.substr(len, len);
            reverse(tmp2.begin(), tmp2.end());
            //cout << tmp << endl << tmp2 << endl;
            if(tmp != tmp2) fail = true;
        }
        else fail = true;
        if(!fail) {
            s = s.substr(0, len);
            ans = len;
        }
    }
    cout << ans << endl;
    return 0;
}
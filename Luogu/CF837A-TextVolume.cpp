#include <iostream>
using namespace std;

int main() {
    int n, len = 0, ans = 0;
    string s;
    cin >> n;
    while(len < n) {
        cin >> s;
        int tmp = 0;
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                tmp++;
        }
        ans = max(ans, tmp);
        len += s.length() + 1;
    }
    cout << ans;
    return 0;
}
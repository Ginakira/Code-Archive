#include <iostream>
typedef long long LL;
using namespace std;

int main() {
    string s;
    LL zn = 0, ans = 0;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'z') zn++;
        else if(s[i] == 'y') ans += zn * (zn - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
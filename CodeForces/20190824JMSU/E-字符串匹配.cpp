#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string pre;

int main() {
    string s;
    size_t pos = 0;
    int T, n;
    long long ans = 0;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int tmp = 1;
        for (int i = 0; i < n; ++i) {
            pre = s.substr(0, tmp++);
            while (pos != s.npos) {
                //cout << pos << endl;
                pos = s.find(pre, pos);
                if(pos != s.npos) ans++, pos++;
                if (ans == 1007) ans = 0;
            }
            pos = 0;
        }
        cout << ans << endl;
    }
    return 0;
}

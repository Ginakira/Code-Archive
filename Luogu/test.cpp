#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int ans[100], a[100], b[100];
int main() {
    int T;
    string s1, s2;
    cin >> T;
    while (T--) {
        cin >> s1 >> s2;
        if(s1 == "0" && s2 == "0") {
            cout << 0 << endl;
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(ans, 0, sizeof(ans));
        int lena = s1.length(), lenb = s2.length();
        for (int i = lena - 1, j = 0; i >= 0; --i) {
            a[i] = s1[j++] - '0';
        }
        for (int i = lenb - 1, j = 0; i >= 0; --i) {
            b[i] = s2[j++] - '0';
        }
        int maxl = lena > lenb ? lena : lenb;
        for (int i = 0; i < maxl; ++i) {
            ans[i] += a[i] + b[i];
            if(ans[i] >= 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        bool flag = false;
        for (int i = maxl; i >= 0; --i) {
            if (ans[i] != 0) flag = true;
            if (ans[i] == 0 && !flag) continue;
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
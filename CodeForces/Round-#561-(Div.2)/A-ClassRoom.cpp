#include <iostream>
#include <string>
using namespace std;

int cal(int a) {
    return (a * a - a) / 2;
}

int cnt[27] = {0};
int main() {
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] < 3) continue;
        else {
            int a = cnt[i] / 2;
            int b = cnt[i] - a;
            ans += cal(a) + cal(b);
        }
    }
    cout << ans << endl;

    return 0;
}
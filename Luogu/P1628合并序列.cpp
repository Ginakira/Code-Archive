#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[100010], fin[100010];

int main() {
    int n;
    cin >> n;
    string tar, tmp;
    for(int i = 0; i < n; ++i) cin >> s[i];
    cin >> tar;
    int len = tar.length(), j = 0;
    for(int i = 0; i < n; ++i) {
        tmp = s[i].substr(0, len);
        if(tmp == tar) fin[j++] = s[i];
    }
    sort(fin, fin + j);
    for(int i = 0; i < j; ++i) cout << fin[i] << endl;
    return 0;
}
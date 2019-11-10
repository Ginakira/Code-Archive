#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> gs;
string s;

int main() {
    int n, m;
    cin >> n >> m;
    getline(cin, s);
    for(int i = 0; i < n; ++i) {
        getline(cin, s);
        if(s[s.length() - 1] != char(13)) s += char(13);
        gs.insert(s);
    }
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        getline(cin, s);
        if(s[s.length() - 1] != char(13)) s += char(13);
        if(gs.find(s) != gs.end()) ans++;
    }
    cout << ans << endl;
    return 0;
}
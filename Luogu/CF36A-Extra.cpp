#include <iostream>
#include <cstdio>
using namespace std;

int ind[110];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') ind[cnt++] = i;
    }
    for (int i = cnt - 2; i > 0; --i) {
        if(ind[i + 1] - ind[i] != ind[i] - ind[i - 1]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
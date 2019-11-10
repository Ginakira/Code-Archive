#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string word[100000], tmp;

int main() {
    string tar;
    int n = 0;
    while (getline(cin, tmp)) {
        if (tmp[0] == NULL) break;
        word[n++] = tmp;
    }
    while (cin >> tar) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (tar == word[i].substr(0, tar.length())) {
                ans++;
                //cout << word[i] << ' ';
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string word[10010];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> word[i];
        sort(word[i].begin(), word[i].end());
    }
    sort(word, word + n);
    int ans = 1;
    string pre = word[0];
    for(int i = 1; i < n; ++i) {
        if(word[i] != pre) {
            ans++;
            pre = word[i];
        }
    }
    cout << ans << endl;
    return 0;
}
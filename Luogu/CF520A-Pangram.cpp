#include <iostream>
using namespace std;

bool cnt[27];

int main() {
    char c;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if(c >= 'A' && c <= 'Z')
            cnt[c - 64] = 1;
        else if(c >= 'a' && c <= 'z')
            cnt[c - 96] = 1;
    }
    for (int i = 1; i <= 26; ++i) {
        if(!cnt[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
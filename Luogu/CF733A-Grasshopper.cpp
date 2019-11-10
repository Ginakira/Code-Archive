#include <iostream>
using namespace std;

int main() {
    string s;
    int maxl = 0, pos = -1;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            maxl = max(maxl, (i - pos));
            pos = i;
        }
    }
    maxl = max(maxl, (int)s.length() - pos);
    cout << maxl;
    return 0;
}
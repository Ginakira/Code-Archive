#include <iostream>
using namespace std;

int main() {
    string s, fin;
    cin >> s;
    int ind;
    for (ind = s.length() - 1; ind >= 0; --ind) {
        if (s[ind] != '0') break;
    }
    int len = ind + 1;
    for (int i = 0; i < len / 2; ++i) {
        if(s[i] != s[len - i - 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
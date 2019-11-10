#include <iostream>
#include <string>
using namespace std;

int main() {
    int l = 0, p = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'o') p++;
        else l++;
    }
    if(p == 0 || l % p == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
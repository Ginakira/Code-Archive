#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s, fin;
    bool lower = false;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') continue;
        fin += '.';
        fin += s[i];
    }
    cout << fin;
    return 0;
}
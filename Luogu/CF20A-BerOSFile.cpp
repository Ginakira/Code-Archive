#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, fin;
    cin >> s;
    bool sta = false;
    for (int i = 0; i < s.length(); ++i) {
        if(i == s.length() - 1 && s[i] == '/' && s.length() != 1)
            break;
        if(!sta && s[i] == '/') {
            fin += '/';
            sta = true;
        }
        else if(s[i] == '/' && sta)
            continue;
        else {
            sta = false;
            fin += s[i];
        }
    }
    if(fin[fin.length() - 1] == '/' && fin.length() > 1)
        fin.erase(fin.length() - 1, 1);
    cout << fin;
    return 0;
}
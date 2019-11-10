#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int ans = 0;
    getline(cin , s);
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != ' ' && s[i] != '\n') ans++;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    while(k--) {
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] > s[i + 1]) {
                s.erase(i, 1);
                break;
            }
        }
    }
    while(s[0] == '0' && s.size() > 1) {
        s.erase(0, 1);
    }
    cout << s << endl;
    return 0;
}
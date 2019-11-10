#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int up = 0, low = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(isupper(s[i])) up++;
        else low++;
    }
    if(up <= low) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    cout << s;
    return 0;
}
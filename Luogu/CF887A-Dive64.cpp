#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    bool flag = false;
    for (char c : s) {
        if (c == '1') flag = true;
        else if(flag)
            ans++;
    }
    if (ans >= 6) cout << "yes";
    else
        cout << "no";
}
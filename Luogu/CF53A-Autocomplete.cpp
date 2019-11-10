#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dic[110];

int main() {
    string tar;
    int n;
    cin >> tar >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dic[i];
    }
    sort(dic, dic + n);
    int len = tar.length();
    for (string s : dic) {
        if(s.substr(0, len) == tar) {
            cout << s;
            return 0;
        }
    }
    cout << tar;
    return 0;
}
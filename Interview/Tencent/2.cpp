#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = true;
    while (found) {
        found = false;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] + s[i - 1] == 196) {
                s.erase(i - 1, 2);
                found = true;
                break;
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}
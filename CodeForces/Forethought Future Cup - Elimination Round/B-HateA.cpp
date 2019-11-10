#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string t, temp;
    cin >> t;
    temp = t;
    int c0, c1;
    c0 = count(t.begin(), t.end(), 'a');
    if(c0 == t.length()) {
        cout << t << endl;
        return 0;
    }
    c1 = t.length() - c0;
    if(c1 % 2 != 0) {
        cout << ":(" << endl;
        return 0;
    }
    string temp2 = t.substr(t.length() - c1 / 2, c1 / 2);
    temp.erase(remove(temp.begin(), temp.end(), 'a'), temp.end());
    temp = temp.substr(0, c1 / 2);
    if(temp == temp2) cout << t.substr(0, t.length() - c1 / 2) << endl;
    else cout << ":(" << endl;
    return 0;
}
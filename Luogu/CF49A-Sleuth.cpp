#include <iostream>
using namespace std;

int main() {
    string s, tmp;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            tmp = s[i];
    }
    if (tmp == "A" || tmp == "a" ||
        tmp == "E" || tmp == "e" ||
        tmp == "I" || tmp == "i" ||
        tmp == "O" || tmp == "o" ||
        tmp == "U" || tmp == "u" ||
        tmp == "Y" || tmp == "y")
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
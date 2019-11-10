#include <iostream>
using namespace std;

int main() {
    string s, fin;
    cin >> s;
    for (int i = s.length() - 1; i > 0; --i) {
        fin += s[i];
    }
    fin += s;
    cout << fin;
}
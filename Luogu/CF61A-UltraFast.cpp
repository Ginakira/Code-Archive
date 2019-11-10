#include <iostream>
using namespace std;

int main() {
    string s1, s2, fin;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        if(s1[i] != s2[i])
            fin += '1';
        else
            fin += '0';
    }
    cout << fin;
    return 0;
}
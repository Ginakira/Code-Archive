#include <iostream>
using namespace std;

int main() {
    string s, fin;
    int n;
    cin >> n >> s;
    if(n <= 3)
        fin += s;
    else if (n % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if(i % 2 == 0 && i != 0)
                fin += '-';
            fin += s[i];
        }
    }
    else {
        for (int i = 0; i < n - 3; ++i) {
            if(i % 2 == 0 && i != 0)
                fin += '-';
            fin += s[i];
        }
        fin += '-';
        fin += s.substr(n - 3, 3);
    }
    cout << fin;
    return 0;
}
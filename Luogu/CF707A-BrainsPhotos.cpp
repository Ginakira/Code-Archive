#include <iostream>
#include <map>
using namespace std;

map<char, int> clr;

int main() {
    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            clr[c]++;
        }
    }
    if (clr['C'] != 0 || clr['M'] != 0 || clr['Y'] != 0) {
        cout << "#Color";
    }
    else
        cout << "#Black&White";
    return 0;
}
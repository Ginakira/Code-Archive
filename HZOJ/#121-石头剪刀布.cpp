#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "TIE";
    } else {
        if((a == 'O' && b == 'Y') || (a == 'Y' && b == 'H') || (a == 'H' && b == 'O')) {
            cout << "MING";
        } else {
            cout << "LI";
        }
    }
    return 0;
}
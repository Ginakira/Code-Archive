#include <iostream>
using namespace std;

int main() {
    char c;
    int d;
    cin >> c >> d;
    if(d == 8 || d == 1) {
        if(c == 'a' || c == 'h') cout << 3;
        else cout << 5;
        return 0;
    }
    if(c == 'h' || c == 'a') cout << 5;
    else cout << 8;
    return 0;
}
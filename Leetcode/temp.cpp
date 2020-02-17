#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void output(string str, int ind) {
    cout << str[ind];
    if (str[ind * 2]) {
        cout << '(';
        output(str, ind * 2);
    }
    if (str[ind * 2 + 1]) {
        cout << ',';
        output(str, ind * 2 + 1);
        // cout << ')';
    }
    cout << ')';
    // if (!str[ind * 2 + 1]) cout << ')';
    return;
}

int main() {
    char str[100], x;
    int ind = 1;
    while (1) {
        scanf("%c", &x);
        if (x == '$') break;
        if (x == ' ') continue;
        str[ind++] = x;
    }
    output(str, 1);
    return 0;
}
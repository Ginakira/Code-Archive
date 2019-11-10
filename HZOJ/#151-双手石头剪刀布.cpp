#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char ml, mr, ll, lr;
    cin >> ml >> mr >> ll >> lr;
    // 1明胜 2李胜 3平
    int winl = 0;
    if ((ml == 'O' && ll == 'Y') || (ml == 'Y' && ll == 'H') ||
        (ml == 'H' && ll == 'O')) {
        winl = 1;
    } else if (ml == ll) {
        winl = 3;
    } else {
        winl = 2;
    }

    if (winl == 1) {
        if ((ml == 'O' && lr == 'Y') || (ml == 'Y' && lr == 'H') ||
            (ml == 'H' && lr == 'O') || (ml == lr)) {
            cout << "MING";
        } else if ((mr == 'O' && lr == 'Y') || (mr == 'Y' && lr == 'H') ||
                   (mr == 'H' && lr == 'O')) {
            cout << "MING";
        } else {
            cout << "LIHUA";
        }
    } else if (winl == 3) {
        if ((mr == 'O' && lr == 'Y') || (mr == 'Y' && lr == 'H') ||
            (mr == 'H' && lr == 'O')) {
            cout << "MING";
        } else if (mr == lr) {
            cout << "TIE";
        } else {
            cout << "LIHUA";
        }
    } else {
        if ((mr == 'O' && ll == 'Y') || (mr == 'Y' && ll == 'H') ||
            (mr == 'H' && ll == 'O')) {
            if ((mr == 'O' && lr == 'Y') || (mr == 'Y' && lr == 'H') ||
                (mr == 'H' && lr == 'O') || (mr == lr)) {
                cout << "MING";
            } else {
                cout << "LIHUA";
            }
        } else {
            cout << "LIHUA";
        }
    }
    return 0;
}
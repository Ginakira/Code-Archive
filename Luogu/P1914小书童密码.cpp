#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char c[60];
    cin >> n;
    cin >> c;
    for (int i = 0; c[i] != '\0'; ++i) {
        if (c[i] + (n % 26) > 'z') {
            c[i] = c[i] - 26 + (n % 26);
        }
        else {
            c[i] += (n % 26);
        }
    }
    cout << c << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int main() {
    int plus = 0, i = 0;
    string s;
    cin >> s;
    for(char c : s) {
        if (c == '+') plus++;
        else
            a[i++] = c - '0';
    }
    sort(a, a + i);
    for (int j = 0; j < i; ++j) {
        cout << a[j];
        if (plus > 0) {
            cout << '+';
            plus--;
        }
    }
    return 0;
}
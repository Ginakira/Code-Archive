#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string word[30];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word[i];
    }
    sort(word, word + n);
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << word[i];
    }
    return 0;
}
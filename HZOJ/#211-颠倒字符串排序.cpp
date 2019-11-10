#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string word[33];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word[i];
        reverse(word[i].begin(), word[i].end());
    }
    sort(word, word + n);
    for (int i = 0; i < n; ++i) {
        cout << word[i] << endl;
    }
    return 0;
}
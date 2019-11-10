#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string name[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name[i];
    }
    for (int i = 0; i < n; ++i) {
        transform(name[i].begin(), name[i].end(), name[i].begin(), ::tolower);
        name[i][0] -= 32;
    }
    sort(name, name + n);
    for (int i = 0; i < n; ++i) {
        cout << name[i] << endl;
    }
    return 0;
}
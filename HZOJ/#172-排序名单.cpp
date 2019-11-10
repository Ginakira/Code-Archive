#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name[10];
    for (int i = 0; i < 10; ++i) {
        cin >> name[i];
    }
    sort(name, name + 10);
    for (int i = 0; i < 10; ++i) {
        cout << name[i] << endl;
    }
    return 0;
}
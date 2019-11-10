#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[12];

int main() {
    for(int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10 - i; ++j) {
            if(a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    for(int i = 0; i < 10; ++i) {
        if(i != 0) cout << ' ';
        cout << a[i];
    }
    return 0;
}
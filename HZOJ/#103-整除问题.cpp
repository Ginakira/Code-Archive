#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a % b) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n != 0) {
        if(n % 10 % 2 == 0) {
            cout << "YES";
            return 0;
        }
        n /= 10;
    }
    cout << "NO";
    return 0;
}
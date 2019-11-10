#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    reverse(n.begin(), n.end());
    cout << n;
    return 0;
}
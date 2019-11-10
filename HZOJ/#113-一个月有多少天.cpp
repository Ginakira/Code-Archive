#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m;
    cin >> y >> m;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) md[2] = 29;
    cout << md[m];
    return 0;
}
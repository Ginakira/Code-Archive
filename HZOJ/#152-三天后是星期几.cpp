#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string day[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                 "Friday", "Saturday", "Sunday"};

int main() {
    int n;
    cin >> n;
    n--;
    if (n + 3 > 6)
        n = (n + 3) % 6 - 1;
    else
        n += 3;
    cout << day[n];
    return 0;
}
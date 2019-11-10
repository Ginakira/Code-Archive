#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string animal[13] = {"rat",   "ox",    "tiger",  "rabbit",  "dragon", "snake",
                     "horse", "sheep", "monkey", "rooster", "dog",    "pig"};
int main() {
    int year;
    cin >> year;
    if (year < 1900)
        year = 12 - abs(year - 1900) % 12;
    else
        year = (year - 1900) % 12;
    cout << animal[year];
    return 0;
}
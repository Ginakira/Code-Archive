#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string n, s;
    int age;
    double weight;
    cin >> n >> s >> age >> weight;
    cout << n << ' ' << s  << ' ' << age << ' ';
    cout << setiosflags(ios::fixed) << setprecision(1) << weight;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int ad, rank, age, work;
    cin >> ad >> rank >> age >> work;
    if((rank <= 50 || ad >= 1) && (age <= 25 || work >= 5)) {
        cout << "ok";
    } else {
        cout << "pass";
    }
    return 0;
}
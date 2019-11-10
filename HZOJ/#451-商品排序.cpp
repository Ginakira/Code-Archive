#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int price[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    sort(price, price + n);
    for (int i = 0; i < n; ++i) {
        cout << price[i] << endl;
    }
    return 0;
}
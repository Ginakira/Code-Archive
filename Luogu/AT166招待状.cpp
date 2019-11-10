#include <iostream>
using namespace std;

int md[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int pre = 0, beh = 0;
    for(int i = 1; i < m1; ++i) pre += md[i];
    pre += d1;
    for(int i = 1; i < m2; ++i) beh += md[i];
    beh += d2;
    cout << beh - pre << endl;
    return 0;
}
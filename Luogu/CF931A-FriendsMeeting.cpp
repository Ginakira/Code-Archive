#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, dis, tir;
    cin >> a >> b;
    dis = abs(a - b);
    if(dis % 2 == 0) {
        tir = (1 + dis / 2) * (dis / 2);
    }
    else {
        tir = (1 + dis / 2) * (dis / 2) + (dis / 2 + 1);
    }
    cout << tir;
    return 0;
}
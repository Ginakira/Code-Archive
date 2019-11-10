#include <iostream>
using namespace std;

int gcd(int a,int b) {
    return b ? gcd(b ,a % b) : a;
}

int lcm(int a,int b) {
    return a * b/ gcd(a, b);
}

int main() {
    int a, b, k;
    cin >> a >> b;
    if(a > b) swap(a, b);
    k = (b - a) - gcd(a, b);
    cout << k << endl;
    return 0;
}
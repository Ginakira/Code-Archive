#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int a) {
    if(a < 2) return false;
    for(int i = 2; i <= sqrt(a); ++i) {
        if(a % i == 0) return false;
    }
    return true;
}

int fac(int a) {
    for(int i = sqrt(a); i > 2; --i) {
        if(i >= 5 && a % i == 0) return i;
    }
    return 0;
}

int main() {
    int k;
    cin >> k;
    if(k < 25 || is_prime(k)) {
        cout << - 1 << endl;
        return 0;
    }
    if(fac(k) == 0) {
        cout << - 1 << endl;
        return 0;
    }
    string vstr[5] = {"aeiou", "eioua", "iouae", "ouaei", "uaeio"};
    if(fac(k) % 5 == 0) {
        int t = fac(k);
        for(int i = 1; i <= k / 5; ++i) {
            cout << vstr[(i - 1) % 5];
        }
        cout << endl;
        return 0;
    }
    string vowel = "aeiou";
    int tmp = k / 5, tmp2 = k % 5;
    for(int i = 0; i < tmp; ++i) cout << vowel;
    cout << vowel.substr(0, tmp2) << endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define MAXN 100010
using namespace std;

bool is_prime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

bool is_palindrome(int a) {
    string s = to_string(a);
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev)
        return true;
    else
        return false;
}

int main() {
    //init_prime();
    int a, b;
    bool first = true;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (is_palindrome(i)) {
            if (is_prime(i)) {
                if (!first) {
                    cout << ' ';
                } else {
                    first = false;
                }
                cout << i;
            }
        }
    }
    return 0;
}
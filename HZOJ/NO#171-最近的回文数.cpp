#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string a) {
    string tmp = a;
    reverse(tmp.begin(), tmp.end());
    if (a == tmp) return true;
    else
        return false;
}

int main() {
    string n;
    cin >> n;
    
    return 0;
}
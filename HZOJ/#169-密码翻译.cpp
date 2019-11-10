#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> mp;
int main() {
    int n, sum = 0, tmp;
    cin >> n;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c >> tmp;
        mp[c] = tmp;
    }
    string key;
    cin >> key;
    for (int i = 0; i < key.length(); ++i) {
        if(key[i] >= 'A' && key[i] <= 'Z') {
            sum += mp[key[i]];
        }
    }
    cout << sum << endl;
    return 0;
}
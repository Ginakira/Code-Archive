#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> s;

int main() {
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << endl;
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        if (it != s.begin()) cout << ' ';
        cout << *it;
    }
    return 0;
}
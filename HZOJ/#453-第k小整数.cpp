#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> num;

int main() {
    int n, k, tmp;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        num.insert(tmp);
    }
    int cnt = 0;
    if(num.size() < k) {
        cout << 0 << endl;
        return 0;
    }
    set<int>::iterator it;
    for (it = num.begin(); cnt < k; ++it) {
        cnt++;
        tmp = *it;
    }
    cout << tmp << endl;
    return 0;
}
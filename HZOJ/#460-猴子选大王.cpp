#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }
    int cnt = 1;
    vector<int>::iterator it = v.begin();
    while (v.size() > 1) {
        if(cnt == k) {
            v.erase(it);
            cnt = 1;
        }
        else cnt++, it++;
        if (it == v.end()) it = v.begin();
        //cout << v.size() << endl;
    }
    cout << v[0];
    return 0;
}
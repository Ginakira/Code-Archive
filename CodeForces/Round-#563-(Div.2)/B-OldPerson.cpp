#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
    int n, tmp;
    bool flag = false;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        a.push_back(tmp);
        if((tmp % 2) != (a[0] % 2)) flag = true;
    }
    if(flag) sort(a.begin(), a.end());
    vector<int>::iterator it = a.begin();
    for(; it != a.end(); ++it) cout << *it << ' ';
    cout << endl;
    return 0;
}
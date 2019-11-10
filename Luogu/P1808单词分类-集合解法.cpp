#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> s;
string tmp;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        sort(tmp.begin(), tmp.end());
        s.insert(tmp);
    }
    cout << s.size() << endl;
    return 0;
}
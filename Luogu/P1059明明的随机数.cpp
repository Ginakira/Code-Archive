#include <iostream>
#include <set>
using namespace std;

int main() {
    int m;
    cin >> m;
    set<int> s;
    while(m--) {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << '\n';
    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << ' ';
    }
    return 0;
}
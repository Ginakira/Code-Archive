#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp) s.insert(tmp);
    }
    cout << s.size();
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    for(int i = 0; i < 10; ++i) {
        int t;
        cin >> t;
        s.insert(t % 42);
    }
    cout << s.size() << endl;
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

set<int> a;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    int ans = 0;
    set<int>::iterator it = a.begin();
    for(int i = 1; i <= a.size(); ++i) {
        if(i > *it) break;
        else {
            ans++;
            it++;
        }
    }
    cout << ans << endl;
    return 0;
}
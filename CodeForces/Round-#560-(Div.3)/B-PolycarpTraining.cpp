#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int ans = 0;
    int j = 1;
    for(int i = 1; i <= n; i++) {
        if(q.top() < j) q.pop();
        else {
            ans++;
            q.pop();
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
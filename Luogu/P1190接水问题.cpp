#include <iostream>
#include <queue>
using namespace std;



priority_queue<int, vector<int>, greater<int> > tap;
queue<int> wait;
queue<int> mid;

int main() {
    int n, m, ans = 0, tmp;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        tap.push(tmp);
    }
    for(int i = 0; i < n - m; ++i) {
        cin >> tmp;
        wait.push(tmp);
    }
    bool empty = false;
    while(!empty) {
        tmp = tap.top();
        //cout << "TMP " << tmp << endl;
        ans += tmp;
        tap.pop();
        int tmp2;
        for(int i = 0; i < m - 1; ++i) {
            tmp2 = tap.top() - tmp;
            mid.push(tmp2);
            tap.pop();
        }
        for(int i = 0; i < m - 1; ++i) {
            tap.push(mid.front());
            mid.pop();
        }
        tap.push(wait.front());
        wait.pop();
        if(wait.empty()) empty = true;
        //cout << ans << endl;
    }
    int max;
    while(!tap.empty()) {
        max = tap.top();
        tap.pop();
    }
    ans += max;
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > q;
priority_queue<int, vector<int>, greater<int> > out;

int main() {
    int n, m;
    cin >> n >> m;
    int tmp;
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        q.push(tmp);
    }
    for(int i = 0; i < n - m; ++i) {
        cin >> tmp;
        if(tmp < q.top()) {
            q.pop();
            q.push(tmp);
        }
    }
    for(int i = 0; i < m; ++i) {
        out.push(q.top());
        q.pop();
    }
    for(int i = 0; i < m; ++i) {
        cout << out.top() << endl;
        out.pop();
    }
    return 0;
}
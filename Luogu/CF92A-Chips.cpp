#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)  {
        q.push(i);
    }
    while(m >= q.front()) {
        q.push(q.front());
        m -= q.front();
        q.pop();
    }
    cout << m;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    int cur_num = 1;
    while (q.size() > 1) {
        if (cur_num == 3) {
            cur_num = 1;
            q.pop();
            continue;
        }
        ++cur_num;
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> p;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) p.push(i);
    while(!p.empty()) {
        for(int i = 1; i <= m; ++i) {
            if(i == m) {
                cout << p.front() << ' ';
                p.pop();
                continue;
            }
            int temp = p.front();
            p.pop();
            p.push(temp);
        }
    }
    return 0;
}
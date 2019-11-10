#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 0, tmp;

void DFS(int x, int s) {
    if(x == 4) {
        if(s == n) ans++;
    }
    else {
        for(int i = 0; i <= tmp; ++i) {
            DFS(x + 1, s + i * i);
        }
    }
}

int main() {
    cin >> n;
    tmp = sqrt(n);
    DFS(0, 0);
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int u[100001];
map <int, int> m;
int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> u[i];
        m[u[i]]++;
    }
    cout << m[1] << endl;
    return 0;
}
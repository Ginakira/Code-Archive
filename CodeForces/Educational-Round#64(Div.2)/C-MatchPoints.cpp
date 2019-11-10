#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans, n, z, num[200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> z;
    for(int i = 0; i < n; ++i) cin >> num[i];
    sort(num, num + n);
    int l = 0, r = 0;
    for(r = 0; r < n; ++r) {
        if(num[r]-num[l] >= z) {
            ans++;
            l++;
        }
    }
    cout << min(n / 2, ans) << endl;
    return 0;
}
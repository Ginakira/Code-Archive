#include <iostream>
#include <climits>
using namespace std;

int a[3010];
int main() {
    int n, m;
    cin >> n >> m;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int min = INT_MAX;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i < m - 1) continue;
        else {
            sum = 0;
            for(int j = 0; j < m; ++j) {
                sum += a[i - j];
            }
            min = sum < min ? sum : min;
            //cout << "SUM " << sum << " MIN " << min << endl;
        }
    }
    cout << min << endl;
    return 0;
}
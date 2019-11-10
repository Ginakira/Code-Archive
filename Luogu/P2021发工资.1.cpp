#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        int ans = 0, m[6] = {100, 50, 10, 5, 2, 1};
        for(int i = 0; i < n; ++i) {
            int salary;
            cin >> salary;
            for(int j = 0; j < 6; ++j) {
                ans += salary / m[j];
                salary -= salary / m[j] * m[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
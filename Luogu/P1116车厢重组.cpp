#include <iostream>
using namespace std;

int num[10001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(num[j] > num[j + 1]) {
                ans++;
                swap(num[j], num[j + 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
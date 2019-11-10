#include <iostream>
using namespace std;

int arr[1010];

int main() {
    int n, tmp, pre = 0, ans = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp <= pre) {
            pre = 1;
            arr[ans++] = cnt;
            cnt = 1;
        } else
            pre = tmp, cnt++;
    }
    arr[ans++] = cnt;
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int num[12] = {0};
    int i;
    for(i = 0; n != 0; ++i) {
        num[i] = n % 10;
        n /= 10;
    }
    if(i == 1) {
        cout << 9 << endl;
        return 0;
    }
    int tmp = num[i - 1];
    for(int j = 0; j < i; ++j) {
        ans += 10 - num[j];
        num[j + 1]++;
    }
    cout << ans + tmp << endl;
}
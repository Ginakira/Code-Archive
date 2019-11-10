#include <iostream>
using namespace std;

int a[200010];

int main() {
    int n, sum = 0, total = 0, day = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int goal = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;
    for (int i = 0; total < goal; ++i) {
        total += a[i];
        day = i + 1;
    }
    cout << day;
    return 0;
}
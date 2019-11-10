#include <iostream>
using namespace std;

int main() {
    int n, a, sum = 0, maxa = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
        maxa = max(maxa, a);
    }
    cout << maxa * n - sum << endl;
    return 0;
}
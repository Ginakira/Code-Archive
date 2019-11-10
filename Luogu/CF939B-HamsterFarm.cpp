#include <iostream>
#include <climits>
typedef long long LL;
using namespace std;

int main() {
    LL n, k, min_left = LLONG_MAX, min_ind, need, tmp;
    cin >> n >> k;
    for (LL i = 1; i <= k; ++i) {
        cin >> tmp;
        if (n % tmp < min_left) {
            min_left = n % tmp;
            min_ind = i;
            need = n / tmp;
        }
    }
    cout << min_ind << ' ' << need;
    return 0;
}
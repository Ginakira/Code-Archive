#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, k, a, minp = INT_MAX;
    cin >> n >> k;
    while(n--) {
        cin >> a;
        if(k % a == 0) {
            minp = min(minp, k / a);
        }
    }
    cout << minp;
    return 0;
}
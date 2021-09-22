#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

// Accepted
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> in(n), out(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> out[i];
    }
    int ans = 0;
    int in_ind = 0, out_ind = 0;
    unordered_set<int> parking;
    vector<int> used(n + 1, false);

    for (int i = 0; i < min(n, k); ++i) {
        used[in[in_ind]] = true;
        parking.insert(in[in_ind]);
        ++in_ind;
    }

    while (out_ind < n) {
        int car = out[out_ind];
        if (parking.count(car) > 0) {
            parking.erase(car);
            while (in_ind < n) {
                if (!used[in[in_ind]]) {
                    used[in[in_ind]] = true;
                    parking.insert(in[in_ind]);
                    ++in_ind;
                    break;
                }
                ++in_ind;
            }
        } else {
            ++ans;
            used[car] = true;
        }
        ++out_ind;
    }

    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
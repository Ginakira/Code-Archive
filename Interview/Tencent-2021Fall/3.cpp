// AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    int use_count = 0, finish_count = 0;

    while (finish_count < n) {
        int left = 0, right = n - 1;
        while (weight[right] == -1) --right;
        while (left < right) {
            if (weight[left] == -1) {
                ++left;
                continue;
            }
            int sum = weight[left] + weight[right];
            if (sum <= w && !(sum & 1)) {
                ++use_count;
                finish_count += 2;
                weight[left] = weight[right] = -1;
                break;
            }
            ++left;
        }
        if (left == right) {
            ++use_count;
            ++finish_count;
            weight[right] = -1;
        }
    }

    cout << use_count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
// 70%
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int check(vector<int> &nums, int ind, int len) {
    int left = nums[ind], right = nums[ind + len - 1];
    for (int i = ind + 1; i < ind + len - 1; ++i) {
        if (nums[i] < left || nums[i] < right) return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = n - 1;
    for (int i = 0; i < n; ++i) {
        int min_val = nums[i + 1];
        for (int j = i + 2; j < n; ++j) {
            if (min_val >= nums[j] && min_val >= nums[i]) {
                ++ans;
                min_val = min(min_val, nums[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

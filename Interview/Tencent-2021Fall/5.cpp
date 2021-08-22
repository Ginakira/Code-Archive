#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void check(vector<int> &nums, int target, int &min_cost) {
    int sum = 0;
    for (int num : nums) {
        if (sum >= min_cost) return;
        sum += abs(target - num);
    }
    min_cost = sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int min_num = INT_MAX, max_num = INT_MIN;
    int pre = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num == pre) continue;
        nums.push_back(num);
        pre = num;
        min_num = min(min_num, num);
        max_num = max(max_num, num);
    }

    int min_cost = INT_MAX;
    for (int i = min_num; i <= max_num; ++i) {
        check(nums, i, min_cost);
    }
    cout << min_cost << endl;
    return 0;
}
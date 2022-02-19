// LeetCode 969 煎饼排序

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        if (is_sorted(arr.begin(), arr.end())) {
            return {};
        }
        vector<int> ans;
        size_t n = arr.size();

        for (int i = n - 1; i >= 0; --i) {
            int max_ind =
                max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (max_ind == i) {
                continue;
            } else if (max_ind == 0) {
                ans.push_back(i + 1);
                reverse(arr.begin(), arr.begin() + i + 1);
            } else {
                // Exchange to the first position
                ans.push_back(max_ind + 1);
                reverse(arr.begin(), arr.begin() + max_ind + 1);
                // Exchange to the right position
                ans.push_back(i + 1);
                reverse(arr.begin(), arr.begin() + i + 1);
            }
        }
        return ans;
    }
};
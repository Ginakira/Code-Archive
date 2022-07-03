// LeetCode 1200 最小绝对差

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
using namespace std;

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> results;
        sort(arr.begin(), arr.end());
        int min_diff = numeric_limits<int>::max();
        for (size_t i = 1, n = arr.size(); i < n; ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                results = {{arr[i - 1], arr[i]}};
            } else if (diff == min_diff) {
                results.emplace_back(initializer_list<int>{arr[i - 1], arr[i]});
            }
        }
        return results;
    }
};
// LeetCode 1338 数组大小减半

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int target = n / 2;
        unordered_map<int, int> mark;
        for (int num : arr) {
            ++mark[num];
        }
        vector<tuple<int, int>> vec(mark.begin(), mark.end());
        ranges::sort(vec, [](auto& lhs, auto& rhs) {
            return get<1>(lhs) > get<1>(rhs);
        });
        int ans = 0;
        for (auto& [_, cnt] : vec) {
            n -= cnt;
            ++ans;
            if (n <= target) {
                break;
            }
        }
        return ans;
    }
};
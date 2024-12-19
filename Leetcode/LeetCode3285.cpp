// LeetCode 3285 找到稳定山的下标

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
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int> ans;
        for (int i = 1; i < n; ++i) {
            if (height[i - 1] > threshold) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
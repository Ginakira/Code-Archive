// LeetCode 1441 用栈操作构建数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1, target_ind = 0;
        vector<string> ans;
        while (target_ind < target.size()) {
            ans.emplace_back("Push");
            if (target[target_ind] != cur) {
                ans.emplace_back("Pop");
            } else {
                ++target_ind;
            }
            ++cur;
        }
        return ans;
    }
};
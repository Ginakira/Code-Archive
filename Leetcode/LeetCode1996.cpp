// LeetCode 1996 游戏中弱角色的数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(),
             [](const auto &a, const auto &b) {
                 return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
             });
        int max_def = 0, ans = 0;
        for (auto &property : properties) {
            if (property[1] < max_def) {
                ++ans;
            } else {
                max_def = property[1];
            }
        }
        return ans;
    }
};
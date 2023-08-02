// LeetCode 822 翻转卡片游戏

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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        int ans = 3000;
        for (auto& num : fronts) {
            if (num < ans && !same.count(num)) {
                ans = num;
            }
        }
        for (auto& num : backs) {
            if (num < ans && !same.count(num)) {
                ans = num;
            }
        }
        return ans % 3000;
    }
};
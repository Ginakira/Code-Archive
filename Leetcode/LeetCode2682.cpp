// LeetCode 2682 找出转圈游戏输家

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
    vector<int> circularGameLosers(int n, int k) {
        unordered_set<int> seen;
        vector<int> loser;
        loser.reserve(n);
        int step = k, cur = 0;
        while (!seen.count(cur)) {
            seen.insert(cur);
            cur = (cur + step) % n;
            step += k;
        }
        for (int i = 0; i < n; ++i) {
            if (!seen.count(i)) {
                loser.emplace_back(i + 1);
            }
        }
        return loser;
    }
};
// LeetCode 2225 找出输掉零场或一场比赛的玩家

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> ans_0, ans_1;
        map<int, int> cnt;
        for (auto &match : matches) {
            int winner = match[0], loser = match[1];
            if (!cnt.count(winner)) {
                cnt[winner] = 0;
            }
            ++cnt[loser];
        }
        for (auto &[id, c] : cnt) {
            if (c == 0) {
                ans_0.emplace_back(id);
            } else if (c == 1) {
                ans_1.emplace_back(id);
            }
        }
        
        return {ans_0, ans_1};
    }
};
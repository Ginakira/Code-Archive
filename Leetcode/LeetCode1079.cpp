// LeetCode 1079 活字印刷

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
   private:
    int dfs(unordered_map<char, int> &cnt, unordered_set<char> &tile,
            int remain) {
        if (remain == 0) {
            return 1;
        }
        int ans = 1;
        for (auto t : tile) {
            if (cnt[t] > 0) {
                --cnt[t];
                ans += dfs(cnt, tile, remain - 1);
                ++cnt[t];
            }
        }
        return ans;
    }

   public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnt;
        unordered_set<char> tile;
        for (char ch : tiles) {
            ++cnt[ch];
            tile.insert(ch);
        }
        return dfs(cnt, tile, tiles.size()) - 1;
    }
};
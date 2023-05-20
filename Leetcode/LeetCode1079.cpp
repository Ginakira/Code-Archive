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
    void backtrack(const string &tiles, int n, unordered_set<string> &results,
                   vector<bool> &vis, string &cur, int index) {
        if (index >= n || results.count(cur) || vis[index]) {
            return;
        }
        vis[index] = true;
        cur.push_back(tiles[index]);
        for (int i = 0; i < n; ++i) {
            backtrack(tiles, n, results, vis, cur, i);
        }
        results.insert(cur);
        cur.pop_back();
        vis[index] = false;
    }

   public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string> results;
        vector<bool> vis(n, false);
        string cur = "";

        for (int i = 0; i < n; ++i) {
            backtrack(tiles, n, results, vis, cur, i);
        }
        return results.size();
    }
};

class Solution2 {
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
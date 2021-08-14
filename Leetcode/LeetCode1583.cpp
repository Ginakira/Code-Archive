// LeetCode 1583 统计不开心的朋友

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int unhappyFriends(int n, vector<vector<int>>& preferences,
                       vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                rank[i][preferences[i][j]] = j;
            }
        }
        vector<int> match(n);
        for (auto& pair : pairs) {
            match[pair[0]] = pair[1];
            match[pair[1]] = pair[0];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int index = rank[i][match[i]];  // 与x配对的y在i好感度列表中的下标
            for (int j = 0; j < index; ++j) {  // 小于这个下标的 都是可能的u
                int u = preferences[i][j], v = match[u];
                if (rank[u][i] < rank[u][v]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
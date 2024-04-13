// LeetCode 2924 找到冠军II

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
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            ++indeg[v];
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                if (ans != -1) {
                    return -1;
                }
                ans = i;
            }
        }
        return ans;
    }
};
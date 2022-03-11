// LeetCode 2049 统计最高分的节点数目

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    int n_;
    vector<vector<int>> children_;
    long long max_ans = 0;
    int max_count = 0;

    int dfs(int node) {
        long long score = 1;
        int n = n_ - 1;

        for (auto& child : children_[node]) {
            int child_node_count = dfs(child);
            score *= child_node_count;
            n -= child_node_count;
        }
        if (node != 0) {
            score *= n;
        }
        if (score > max_ans) {
            max_ans = score;
            max_count = 1;
        } else if (score == max_ans) {
            ++max_count;
        }
        return n_ - n;
    }

   public:
    int countHighestScoreNodes(vector<int>& parents) {
        n_ = parents.size();
        children_.resize(n_, vector<int>());
        for (size_t i = 0; i < n_; ++i) {
            int p = parents[i];
            if (p == -1) continue;
            children_[p].emplace_back(i);
        }
        dfs(0);
        return max_count;
    }
};
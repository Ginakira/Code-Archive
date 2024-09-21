// LeetCode 2374 边积分最高的节点

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
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> indeg(n);
        for (int i = 0; i < n; ++i) {
            indeg[edges[i]] += i;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (indeg[i] > indeg[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
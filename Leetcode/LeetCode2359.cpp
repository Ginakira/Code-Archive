// LeetCode 2359 找到离给定两个节点最近的点

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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto calc_dis = [&](int x) {
            vector<int> dis(n, n);
            for (int d = 0; x >= 0 && dis[x] == n; x = edges[x]) {
                dis[x] = d++;
            }
            return dis;
        };
        vector<int> dis1 = calc_dis(node1);
        vector<int> dis2 = calc_dis(node2);

        int min_dis = n, ans = -1;
        for (int i = 0; i < n; ++i) {
            int d = max(dis1[i], dis2[i]);
            if (d < min_dis) {
                min_dis = d;
                ans = i;
            }
        }
        return ans;
    }
};
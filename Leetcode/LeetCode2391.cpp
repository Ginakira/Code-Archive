// LeetCode 2391 收集垃圾的最少总时间

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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int res = 0, cur_dis = 0;
        unordered_map<char, int> distance;
        for (int i = 0; i < n; ++i) {
            res += garbage[i].size();
            if (i > 0) {
                cur_dis += travel[i - 1];
            }
            for (auto c : garbage[i]) {
                distance[c] = cur_dis;
            }
        }
        for (auto& [_, dis] : distance) {
            res += dis;
        }
        return res;
    }
};
// LeetCode 1921 消灭怪物的最大数量

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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); ++i) {
            // dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] ? 1 : 0);
            dist[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        int ans = 0;
        for (int t = 0; int d : dist) {
            if (d > t) {
                ++ans;
                ++t;
            } else {
                break;
            }
        }
        return ans;
    }
};
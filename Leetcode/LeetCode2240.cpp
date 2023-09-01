// LeetCode 2240 买钢笔和铅笔的方案数
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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (int i = 0; i <= total / cost1; ++i) {
            long long remain = total - cost1 * i;
            ans += remain / cost2 + 1;
        }
        return ans;
    }
};
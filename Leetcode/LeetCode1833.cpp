// LeetCode 1833 雪糕的最大数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序 + 贪心
class Solution {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(), costs.end());
        for (int cost : costs) {
            if (coins < cost) {
                break;
            }
            coins -= cost;
            ++count;
        }
        return count;
    }
};

// 计数排序 + 贪心
class Solution2 {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count[100001] = {0};
        for (int& cost : costs) {
            count[cost]++;
        }

        int ans = 0;
        for (int i = 1; i < 100001; ++i) {
            if (i > coins) {
                break;
            }
            int pcs = min(count[i], coins / i);
            coins -= i * pcs;
            ans += pcs;
        }
        return ans;
    }
};
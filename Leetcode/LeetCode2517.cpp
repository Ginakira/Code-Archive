// LeetCode 2517 礼盒的最大甜蜜度

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
    bool check(const vector<int>& price, int k, int sweetness) {
        int prev = -sweetness;
        int cnt = 0;
        for (int p : price) {
            if (p - prev >= sweetness) {
                ++cnt;
                prev = p;
            }
            if (cnt >= k) {
                return true;
            }
        }
        return false;
    }

   public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
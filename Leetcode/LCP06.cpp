// LCP 06 拿硬币

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
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (int coin : coins) {
            ans += (coin + 1) / 2;
        }
        return ans;
    }
};
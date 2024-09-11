// LeetCode 2555 两个线段获得的最多奖品

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
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        if (prizePositions[n - 1] - prizePositions[0] <= k * 2 + 1) {
            return n;
        }
        int ans = 0, mx = 0, left = 0, right = 0;
        for (int mid = 0; mid < n; ++mid) {
            // second segment
            while (right < n &&
                   prizePositions[right] - prizePositions[mid] <= k) {
                ++right;
            }
            ans = max(ans, mx + right - mid);
            // first segment
            while (prizePositions[mid] - prizePositions[left] > k) {
                ++left;
            }
            mx = max(mx, mid - left + 1);
        }
        return ans;
    }
};
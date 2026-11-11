// LeetCode 3789 采购的最小消费

class Solution {
 public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                        int need2) {
    long long ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
    int max_need = max(need1, need2);
    long long ans2 = 1LL * costBoth * max_need;
    if (need1 > need2) {
      swap(need1, need2);
      swap(cost1, cost2);
    }
    long long ans3 = 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1);
    return min({ans1, ans2, ans3});
  }
};
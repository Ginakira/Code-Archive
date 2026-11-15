// LeetCode 1524 和为奇数的子数组数目

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int n = arr.size();
    vector<int> presum(n + 1);
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = (presum[i] + arr[i]) % 2;
    }

    array<int, 2> cnt{};
    long long ans = 0;
    for (int s : presum) {
      ans += cnt[s ^ 1];
      ++cnt[s];
    }
    return ans % 1'000'000'007;
  }
};
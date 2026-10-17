// LeetCode 3551 数位和排序需要的最小交换次数

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int n = nums.size();
    auto sum_digit = [](int num) {
      int sum = 0;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      return sum;
    };
    vector<int> order(n);
    ranges::iota(order, 0);
    ranges::sort(order, [&](int a, int b) {
      int sum_a = sum_digit(nums[a]);
      int sum_b = sum_digit(nums[b]);
      if (sum_a == sum_b) {
        return nums[a] < nums[b];
      }
      return sum_a < sum_b;
    });

    int ans = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      int j = i;
      int len = 0;
      while (!visited[j]) {
        visited[j] = true;
        j = order[j];
        ++len;
      }
      ans += len - 1;
    }
    return ans;
  }
};
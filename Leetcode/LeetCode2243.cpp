// LeetCode 2243 计算字符串的数字和

class Solution {
 public:
  string digitSum(string s, int k) {
    string ans = s;
    while (ans.size() > k) {
      string cur{};
      for (auto chunk : ans | std::views::chunk(k)) {
        int sum = 0;
        for (const char c : chunk) {
          sum += c - '0';
        }
        cur += to_string(sum);
      }
      ans = std::move(cur);
    }
    return ans;
  }
};
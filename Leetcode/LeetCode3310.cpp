// LeetCode 3310 移除可疑的方法

class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> callees(n), callers(n);
    vector<int8_t> bad_funcs(n, false);
    for (auto& inv : invocations) {
      int caller = inv[0], callee = inv[1];
      callees[caller].emplace_back(callee);
      callers[callee].emplace_back(caller);
    }
    vector<int8_t> seen(n, false);
    auto dfs = [&](this auto& dfs, int cur) {
      if (seen[cur]) {
        return;
      }
      seen[cur] = true;
      bad_funcs[cur] = true;
      for (int callee : callees[cur]) {
        dfs(callee);
      }
    };
    dfs(k);

    vector<int> ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (bad_funcs[i]) {
        for (int caller : callers[i]) {
          if (!bad_funcs[caller]) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
          }
        }
        continue;
      }
      ans.emplace_back(i);
    }
    return ans;
  }
};
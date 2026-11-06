// LeetCode 2747 统计没有收到请求的服务器数目

class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                           vector<int>& queries) {
    ranges::sort(logs, {}, [](auto& p) { return p[1]; });
    vector<int> idx(queries.size());
    ranges::iota(idx, 0);
    ranges::sort(idx, {}, [&](int i) { return queries[i]; });
    vector<int> cnt(n + 1);
    int not_receives = n;
    int left = 0, right = 0;

    for (int qid : idx) {
      int& q = queries[qid];
      while (right < logs.size() && logs[right][1] <= q) {
        int i = logs[right][0];
        if (cnt[i] == 0) {
          --not_receives;
        }
        ++cnt[i];
        ++right;
      }
      while (left < logs.size() && logs[left][1] < q - x) {
        int i = logs[left][0];
        --cnt[i];
        if (cnt[i] == 0) {
          ++not_receives;
        }
        ++left;
      }
      q = not_receives;
    }
    return queries;
  }
};
// LeetCode 1331 数字序号转换

#include <algorithm>
#include <numeric>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> arr_ind;
    for (int i = 0; i < arr.size(); ++i) {
      arr_ind.emplace_back(i);
    }
    sort(arr_ind.begin(), arr_ind.end(),
         [&arr](auto &a, auto &b) { return arr[a] < arr[b]; });
    for (int i = 0, rank = 1, last = 0; i < arr_ind.size(); ++i) {
      if (i > 0 && arr[arr_ind[i]] != last) {
        ++rank;
      }
      last = arr[arr_ind[i]];
      arr[arr_ind[i]] = rank;
    }
    return arr;
  }
};

class Solution2 {
 public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sorted_arr = arr;
    ranges::sort(sorted_arr);

    unordered_map<int, int> ids;
    for (int i = 0, id = 1; i < sorted_arr.size(); ++i) {
      if (i == 0 || sorted_arr[i] == sorted_arr[i - 1]) {
        ids[sorted_arr[i]] = id;
      } else {
        ids[sorted_arr[i]] = ++id;
      }
    }

    return arr | ranges::views::transform([&](int x) { return ids[x]; }) |
           ranges::to<std::vector>();
  }
};
// 1356. 根据数字二进制下 1 的数目排序
#include <algorithm>
#include <bitset>
#include <vector>
using std::bitset;
using std::sort;
using std::vector;

// 解法1：sort + 位运算
class Solution {
 public:
  int hummingWeight(int num) {
    int ret = 0;
    while (num) {
      if (num & 1) ret++;
      num >>= 1;
    }
    return ret;
  }

  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int num_a = hummingWeight(a), num_b = hummingWeight(b);
      if (num_a == num_b) {
        return a < b;
      }
      return num_a < num_b;
    });
    return arr;
  }
};

// bitset
class Solution2 {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int num_a = bitset<32>(a).count(), num_b = bitset<32>(b).count();
      if (num_a == num_b) {
        return a < b;
      }
      return num_a < num_b;
    });
    return arr;
  }
};

class Solution3 {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    ranges::sort(arr, [](int a, int b) {
      int cnt_a = __builtin_popcount(a), cnt_b = __builtin_popcount(b);
      return cnt_a == cnt_b ? a < b : cnt_a < cnt_b;
    });
    return arr;
  }
};
// LeetCode 1865 找出和为指定值的下标对

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

class FindSumPairs {
 private:
  map<int, int> mark1;
  unordered_map<int, int> mark2;
  vector<int>& nums2;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums2(nums2) {
    for (int num : nums1) {
      ++mark1[num];
    }
    for (int num : nums2) {
      ++mark2[num];
    }
  }

  void add(int index, int val) {
    int old_v = nums2[index];
    int new_v = old_v + val;
    nums2[index] = new_v;
    --mark2[old_v];
    ++mark2[new_v];
  }

  int count(int tot) {
    int ans = 0;
    for (auto [num, cnt] : mark1) {
      if (num >= tot) {
        break;
      }
      int target = tot - num;
      if (mark2.contains(target)) {
        ans += cnt * mark2[target];
      }
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
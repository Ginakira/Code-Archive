// LeetCode 3876 构造奇偶一致的数组 II

class Solution {
 public:
  bool uniformArray(vector<int>& nums1) {
    int min_odd = numeric_limits<int>::max();

    for (int num : nums1) {
      if (num & 1) {
        min_odd = min(min_odd, num);
      }
    }

    bool all_odd = true, all_even = true;
    for (int num : nums1) {
      if (num <= min_odd) {
        if (num & 1) {
          all_even = false;
        } else {
          all_odd = false;
        }
      }
    }
    return all_odd || all_even;
  }
};
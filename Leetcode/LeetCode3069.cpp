// LeetCode 3069 将元素分配到两个数组中 I

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> vec_a{nums[0]}, vec_b{nums[1]};
    vec_a.reserve(nums.size());
    for (int i = 2; i < nums.size(); ++i) {
      if (vec_a.back() > vec_b.back()) {
        vec_a.emplace_back(nums[i]);
      } else {
        vec_b.emplace_back(nums[i]);
      }
    }
    vec_a.insert(vec_a.end(), std::make_move_iterator(vec_b.begin()),
                 std::make_move_iterator(vec_b.end()));
    return vec_a;
  }
};
// LeetCode 2349 设计数字容器系统

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

class NumberContainers {
 private:
  std::unordered_map<int, std::set<int>> num_to_idx_;
  std::unordered_map<int, int> idx_to_num_;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    if (idx_to_num_.count(index)) {
      int old_num = idx_to_num_[index];
      num_to_idx_[old_num].erase(index);
    }
    idx_to_num_[index] = number;
    num_to_idx_[number].emplace(index);
  }

  int find(int number) {
    if (num_to_idx_[number].empty()) {
      return -1;
    }
    return *num_to_idx_[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
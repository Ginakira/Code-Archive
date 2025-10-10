// LeetCode 3147 从魔法师身上吸取的最大能量

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

class Solution {
 public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int ans = numeric_limits<int>::min();
    energy.resize(n + k);
    for (int i = n - 1; i >= 0; --i) {
      energy[i] += energy[i + k];
      ans = max(ans, energy[i]);
    }
    return ans;
  }
};
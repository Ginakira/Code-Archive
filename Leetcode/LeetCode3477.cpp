// LeetCode 3477 水果成篮II

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
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int ans = fruits.size();
    for (int fruit : fruits) {
      for (int& basket : baskets) {
        if (basket >= fruit) {
          basket = -1;
          --ans;
          break;
        }
      }
    }
    return ans;
  }
};
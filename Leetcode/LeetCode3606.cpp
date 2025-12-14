// LeetCode 3606 优惠券校验器

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
 private:
  bool is_valid_id(const std::string& id) {
    if (id.empty()) {
      return false;
    }
    for (char c : id) {
      if (!isalnum(c) && c != '_') {
        return false;
      }
    }
    return true;
  }

 public:
  vector<string> validateCoupons(vector<string>& code,
                                 vector<string>& businessLine,
                                 vector<bool>& isActive) {
    static const unordered_map<string, int> BUSINESS_LINE_TO_CATEGORY = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3},
    };
    int n = code.size();
    vector<string> group[4];
    for (int i = 0; i < n; ++i) {
      const string &id = code[i], bline = businessLine[i];
      if (!isActive[i]) {
        continue;
      }
      if (auto it = BUSINESS_LINE_TO_CATEGORY.find(bline);
          it != BUSINESS_LINE_TO_CATEGORY.end() && is_valid_id(id)) {
        group[it->second].emplace_back(id);
      }
    }

    vector<string> ans;
    for (auto& g : group) {
      ranges::sort(g);
      ans.insert(ans.end(), g.begin(), g.end());
    }
    return ans;
  }
};
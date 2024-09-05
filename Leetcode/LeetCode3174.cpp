// LeetCode 3174 清楚数字

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
    string clearDigits(string s) {
        std::string filtered;
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!filtered.empty()) {
                    filtered.pop_back();
                }
            } else {
                filtered.push_back(ch);
            }
        }
        return filtered;
    }
};
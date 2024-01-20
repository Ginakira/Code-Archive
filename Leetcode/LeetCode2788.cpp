// LeetCode 2788 按分隔符拆分字符串

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> splitWordsBySeparator(vector<string>& words,
                                         char separator) {
        vector<string> ans;
        for (auto& word : words) {
            stringstream ss(word);
            string cur;
            while (getline(ss, cur, separator)) {
                if (!cur.empty()) {
                    ans.emplace_back(cur);
                }
            }
        }
        return ans;
    }
};
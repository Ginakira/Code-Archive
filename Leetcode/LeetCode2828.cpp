// LeetCode 2828 判别首字母缩略词

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
    bool isAcronym(vector<string> &words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        return s == std::accumulate(
                        words.begin(), words.end(), std::string{},
                        [](const std::string &acc, const std::string &word) {
                            return acc + word[0];
                        });
    }
};
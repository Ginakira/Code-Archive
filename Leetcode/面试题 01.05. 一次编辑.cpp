// 面试题 01.05. 一次编辑

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool oneInsertAway(const std::string &longer, const std::string &shorter) {
        size_t n = longer.size(), m = shorter.size();
        if (n - m > 1) return false;
        size_t inda = 0, indb = 0;
        while (inda < n && indb < m) {
            if (longer[inda] == shorter[indb]) {
                ++inda;
                ++indb;
            } else {
                ++inda;
            }
            if (inda - indb > 1) {
                return false;
            }
        }
        return true;
    }

   public:
    bool oneEditAway(string first, string second) {
        size_t n = first.size(), m = second.size();
        bool ans = false;
        if (n > m) {
            ans = oneInsertAway(first, second);
        } else if (n < m) {
            ans = oneInsertAway(second, first);
        } else {
            bool already_diff = false;
            ans = true;
            for (size_t i = 0; i < n; ++i) {
                if (first[i] != second[i]) {
                    if (already_diff) {
                        ans = false;
                        break;
                    }
                    already_diff = true;
                }
            }
        }
        return ans;
    }
};
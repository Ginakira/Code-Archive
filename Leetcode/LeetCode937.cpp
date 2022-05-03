// LeetCode 937 重新排列日志文件

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(), logs.end(),
                    [](const string &loga, const string &logb) {
                        size_t posa = loga.find_first_of(" ");
                        size_t posb = logb.find_first_of(" ");
                        bool is_digit_a = isdigit(loga[posa + 1]);
                        bool is_digit_b = isdigit(logb[posb + 1]);
                        if (is_digit_a && is_digit_b) {
                            return false;
                        }
                        if (!is_digit_a && !is_digit_b) {
                            string sa = loga.substr(posa + 1);
                            string sb = logb.substr(posb + 1);
                            return sa == sb ? loga < logb : sa < sb;
                        }
                        return is_digit_a ? false : true;
                    });
        return logs;
    }
};
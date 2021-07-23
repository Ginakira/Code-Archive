// LeetCode 551 学生出勤记录

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 朴素遍历计数
class Solution {
   public:
    bool checkRecord(string s) {
        int n = s.size();
        int a_count = 0, ind = 0;
        while (ind < n) {
            if (s[ind] == 'A') {
                ++a_count;
                if (a_count > 1) {
                    return false;
                }
                ++ind;
            } else if (s[ind] == 'L') {
                int next_ind = ind + 1;
                while (s[next_ind] == 'L' && next_ind < n) {
                    ++next_ind;
                }
                if (next_ind - ind > 2) {
                    return false;
                }
                ind = next_ind;
            } else {
                ++ind;
            }
        }
        return true;
    }
};

// STL
class Solution2 {
   public:
    bool checkRecord(string s) {
        int a_count = count(s.begin(), s.end(), 'A');
        auto l_it = s.find("LLL");
        return a_count < 2 && l_it == string::npos;
    }
};
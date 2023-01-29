// LeetCode 2315 统计星号

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countAsterisks(string s) {
        bool in_line = false;
        int cnt = 0;
        for (char ch : s) {
            if (ch == '|') {
                in_line = !in_line;
            }
            cnt += (!in_line && ch == '*');
        }
        return cnt;
    }
};
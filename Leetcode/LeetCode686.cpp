// LeetCode 686 重复叠加字符串匹配

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string sa;
        while (sa.size() < 2 * a.size() + b.size()) {
            sa += a;
            ++count;
            if (sa.find(b) != string::npos) {
                return count;
            }
        }
        return -1;
    }
};
// LeetCode 541 反转字符串II
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseStr(string s, int k) {
        auto it = s.begin();
        while (it != s.end()) {
            if (s.end() - it < k) {
                reverse(it, s.end());
                break;
            }
            reverse(it, it + k);
            it += 2 * k;
        }
        return s;
    }
};
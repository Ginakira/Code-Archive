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

// 不借助STL
class Solution2 {
   private:
    void reverse_helper(string &s, int start, int end) {
        if (start >= end) return;
        while (start < end) {
            swap(s[start], s[end]);
            ++start, --end;
        }
    }

   public:
    string reverseStr(string s, int k) {
        int n = s.size(), cur = 0;
        while (cur < n) {
            if (n - cur < k) {
                reverse_helper(s, cur, n - 1);
                break;
            }
            reverse_helper(s, cur, cur + k - 1);
            cur += 2 * k;
        }
        return s;
    }
};
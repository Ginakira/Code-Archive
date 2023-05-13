// LeetCode 1016 子串能表示从1到N数字的二进制串

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
   private:
    string ToBinaryString(int i) {
        string s;
        do {
            s.push_back('0' + (i & 1));
            i >>= 1;
        } while (i);
        reverse(s.begin(), s.end());
        return s;
    }

   public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; ++i) {
            auto bin_s = ToBinaryString(i);
            if (s.find(bin_s) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
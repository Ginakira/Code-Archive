// LeetCOde 788 旋转数字

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool is_good_number(int num) {
        string s = to_string(num);
        bool has_diff = false;
        for (char &c : s) {
            if (c == '0' || c == '1' || c == '8') {
                continue;
            } else if (c == '2' || c == '5' || c == '6' || c == '9') {
                has_diff = true;
            } else {
                return false;
            }
        }
        return has_diff;
    }

   public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (is_good_number(i)) {
                ++ans;
            }
        }
        return ans;
    }
};
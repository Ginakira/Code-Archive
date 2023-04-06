// LeetCode 1017 负二进制转换

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string baseNeg2(int n) {
        string ans;
        while (n) {
            int remainder = n % 2;
            ans.push_back(abs(remainder) + '0');
            n = remainder >= 0 ? (n / -2) : (n / -2 + 1);
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};
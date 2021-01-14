// LeetCode 1018 可被5整除的二进制前缀
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int sum = 0;
        for (const auto& bit : A) {
            sum <<= 1;
            sum |= bit;
            ret.emplace_back(sum % 5 == 0);
            sum %= 10;
        }
        return ret;
    }
};
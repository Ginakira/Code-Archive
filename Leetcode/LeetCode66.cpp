// LeetCode 66 加一
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        for (int i = n - 1; i > 0; --i) {
            if (digits[i] >= 10) {
                digits[i] -= 10;
                digits[i - 1]++;
            }
        }
        if (digits[0] >= 10) {
            digits[0] -= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
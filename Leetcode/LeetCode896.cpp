// LeetCode 896 单调数列
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        int asc_valid = true, desc_valid = true;
        for (int i = 1; i < n && (asc_valid || desc_valid); ++i) {
            if (asc_valid && A[i] < A[i - 1]) {
                asc_valid = false;
            }
            if (desc_valid && A[i] > A[i - 1]) {
                desc_valid = false;
            }
        }
        return asc_valid || desc_valid;
    }
};
// LeetCode 1004 最大连续1的个数III
#include <vector>
using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0, right = 0;
        int count = 0;
        while (right < n) {
            if (A[right] == 1) {
                ++count;
            }
            if (right - left + 1 - count > K) {
                if (A[left] == 1) {
                    --count;
                }
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};
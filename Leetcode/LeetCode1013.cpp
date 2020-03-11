// 每日一题 将数组分成和相等的三个部分
#include <vector>
using namespace std;

// 两个指针 找切分点 48ms
class Solution {
   public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, n = A.size();
        for (int i : A) sum += i;
        int target = sum / 3, lsum = 0, rsum = 0, l = 0, r = n - 1;
        do {
            lsum += A[l++];
        } while (lsum != target && l < n);
        do {
            rsum += A[r--];
        } while (rsum != target && r >= 0);
        return l <= r;
    }
};
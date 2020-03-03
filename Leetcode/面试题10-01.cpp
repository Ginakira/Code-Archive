// 合并排序的数组
#include <vector>
using namespace std;

// 因为A数组后面有足够的缓冲空间 所以从A末尾开始向前存
// 其他步骤同归并排序合并数组
class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1, p = m + n - 1;
        while (pa >= 0 || pb >= 0) {
            if (pb < 0 || (pa >= 0 && A[pa] > B[pb])) {
                A[p--] = A[pa--];
            } else {
                A[p--] = B[pb--];
            }
        }
        return;
    }
};
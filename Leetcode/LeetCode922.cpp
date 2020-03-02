#include <vector>
using namespace std;

// 解法1： 24ms
// 如果当前位不满足规则，则从下一位开始向后找第一个可以满足该位置要求的数字
// 也就是奇偶性一致，找到后与当前位置的数值进行交换
// 其中  !((i & 1) ^ (ret[i] & 1))等价于(i & 1) == (ret[i] & 1)
class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (!((i & 1) ^ (A[i] & 1))) continue;
            for (int j = i + 1; j < n; ++j) {
                if (!((i & 1) ^ (A[j] & 1))) {
                    swap(A[i], A[j]);
                    break;
                }
            }
        }
        return A;
    }
};

// 解法2: 28ms
// 遍历一遍 分别在新数组对应位置中记录奇偶 维护两个当前下标的变量
// odd代表现在奇数元素要存入的下标 even代表现在偶数元素要存入的下标
class Solution2 {
   public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size(), even = 0, odd = 1;
        vector<int> ans(n);
        for (auto i : A) {
            if (i & 1)
                ans[odd] = i, odd += 2;
            else
                ans[even] = i, even += 2;
        }
        return ans;
    }
};
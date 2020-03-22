// 每日一题 使数组唯一的最小增量
#include <vector>
using namespace std;

// 暴力法哈希 2760ms
class Solution {
   public:
    int minIncrementForUnique(vector<int>& A) {
        int num_set[100000] = {0};
        int ans = 0;
        for (int& i : A) {
            while (num_set[i]) i++, ans++;
            num_set[i] = 1;
        }
        return ans;
    }
};

// 先进行排序 76ms
class Solution2 {
   public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0, cur_max = -1, tmp;
        for (int& i : A) {
            if (i <= cur_max) {
                tmp = cur_max + 1;
                ans += tmp - i;
                i = tmp;
            }
            cur_max = max(cur_max, i);
        }
        return ans;
    }
};
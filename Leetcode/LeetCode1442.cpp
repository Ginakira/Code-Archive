// LeetCode 1442 行程两个异或相等数组的三元组数目
#include <unordered_map>
#include <vector>
using namespace std;

// 双层循环
class Solution {
   public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre_xor(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre_xor[i] = pre_xor[i - 1] ^ arr[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (pre_xor[j + 1] != pre_xor[i]) continue;
                ans += j - i;
            }
        }
        return ans;
    }
};

// 哈希表
class Solution2 {
   public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre_xor(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre_xor[i] = pre_xor[i - 1] ^ arr[i - 1];
        }

        unordered_map<int, int> cnt, total;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt.count(pre_xor[i + 1])) {
                ans += i * cnt[pre_xor[i + 1]] - total[pre_xor[i + 1]];
            }
            ++cnt[pre_xor[i]];
            total[pre_xor[i]] += i;
        }
        return ans;
    }
};

// 哈希表（空间优化）
class Solution3 {
   public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, pre_xor = 0;
        unordered_map<int, int> cnt, total;
        for (int i = 0; i < n; ++i) {
            int xor_val = pre_xor ^ arr[i];
            if (cnt.count(xor_val)) {
                ans += i * cnt[xor_val] - total[xor_val];
            }
            ++cnt[pre_xor];
            total[pre_xor] += i;
            pre_xor = xor_val;
        }
        return ans;
    }
};
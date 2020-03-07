// 最长连续序列
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 暴力法 TLE n^3级别
// 以每一项作为开头枚举后面的数 直到这个数在数组中没出现过
class Solution {
   public:
    bool array_contains(vector<int> arr, int num) {
        for (int i : arr) {
            if (i == num) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        for (int i : nums) {
            int current_len = 1, current_num = i + 1;
            while (array_contains(nums, current_num))
                current_len++, current_num++;
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};

// 排序法 4ms nlogn级别
class Solution2 {
   public:
    int longestConsecutive(vector<int>& nums) {
        int current_len = 1, max_len = 1, n = nums.size();
        if (n < 2) return n;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) {
                current_len++;
            } else {
                max_len = max(max_len, current_len);
                current_len = 1;
            }
        }
        return max(max_len, current_len);
    }
};

// 哈希表法 8ms
// 算法思想同暴力法
// 如果以a作为序列开头时，a-1已经出现过，就不用枚举以a开头的序列了，因为a一定出现在别的序列中
class Solution3 {
   public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> num_set;
        for (int i : nums) num_set.insert(i);
        for (int i : nums) {
            if (num_set.count(i - 1)) continue;
            int current_len = 0, current_num = i;
            while (num_set.count(current_num)) current_len++, current_num++;
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};

// 并查集 与哈希表法思想相仿 16ms
// 如果存在当前数字的下一个数字 就合并到这个数字的集合中 然后计算长度
class Solution4 {
   private:
    unordered_map<int, int> uf, cnt;

   public:
    int find(int x) { return x == uf[x] ? x : uf[x] = find(uf[x]); }

    int merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return cnt[fa];
        uf[fb] = a, cnt[fa] += cnt[fb];
        return cnt[fa];
    }

    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ans = 1;
        for (int i : nums) uf[i] = i, cnt[i] = 1;
        for (int i : nums) {
            if (uf.count(i + 1)) ans = max(ans, merge(i, i + 1));
        }
        return ans;
    }
};
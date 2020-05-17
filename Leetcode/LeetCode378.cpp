// 有序矩阵中第K小的元素
#include <queue>
#include <vector>
using namespace std;

// 暴力&排序法 68ms 15.4MB
class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int nums[matrix.size() * matrix[0].size()], cnt = 0;
        for (auto v : matrix) {
            for (auto i : v) {
                nums[cnt++] = i;
            }
        }
        sort(nums, nums + cnt);
        return nums[k - 1];
    }
};

// STL-优先队列/大顶堆 维护一个大小为k的大顶堆 最终堆顶即为结果
class Solution2 {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (auto v : matrix) {
            for (auto i : v) {
                q.push(i);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};

// 杨氏矩阵 二分 + 判定
class Solution3 {
   public:
    int check(vector<vector<int>>& matrix, int x, int n, int m) {
        int cnt = 0, j = n;
        for (int i = 0; i < m; ++i) {
            while (j && matrix[j - 1][i] > x) --j;
            cnt += j;
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n - 1][m - 1];
        int mid, ret;
        while (l < r) {
            mid = (l + r) >> 1;
            ret = check(matrix, mid, n, m);  // 小于等于mid的个数
            if (ret < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
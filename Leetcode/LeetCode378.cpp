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
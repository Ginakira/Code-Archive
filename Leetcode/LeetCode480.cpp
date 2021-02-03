// LeetCode 480 滑动窗口中位数
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 对顶堆 + 延迟删除
// small维护较小的一半，大小应始终等于large或比large多一，为大顶堆
// large反之，为小顶堆
// 当窗口滑动，需要删除最左侧元素时，因为队列无法删除除队首以外的元素，所以采用延迟删除的方法
// 也就是说，不立即删除，而是记录下对应的元素还需要删除多少次
// prune方法，为调整队首，如果队首是已经删除了的元素那么出队，直到队首合法
// 所以当要删除当元素为队首时，应该额外单独调用prune
// 在每次调用getMedian之前，我们都应保证两个堆的大小是符合规则的
// 所以在每次进行插入删除操作后，我们都调用makeBalance方法维护堆大小平衡
// 如果small的大小比large多2个，那么弹出队首插入large
// 如果small比large少，那么弹出large的队首给small
// 因为在维护大小平衡的过程中，其中一个堆的队首发生了改变，为了保证下次操作时队首一定是合法的，所以在调整完后需要调用prune对被出队的那个堆进行队首调整

class DualHeap {
   private:
    priority_queue<int> small;  // 记录较小的一半 大根堆
    priority_queue<int, vector<int>, greater<int>>
        large;                        // 记录较大的一半 小根堆
    unordered_map<int, int> delayed;  // 延迟删除 记录元素剩余的应删除次数
    int k;                            // 总数
    int smallSize;                    // 目前小元素数
    int largeSize;                    // 目前大元素数

    template <typename T>
    void prune(T& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (!delayed.count(num)) break;
            --delayed[num];
            if (delayed[num] == 0) {
                delayed.erase(num);
            }
            heap.pop();
        }
        return;
    }

    void makeBalance() {
        if (smallSize - largeSize >= 2) {
            large.push(small.top());
            small.pop();
            --smallSize, ++largeSize;
            prune(small);
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize, --largeSize;
            prune(large);
        }
        return;
    }

   public:
    DualHeap(int __k) : k(__k), smallSize(0), largeSize(0) {}

    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            ++smallSize;
            small.push(num);
        } else {
            ++largeSize;
            large.push(num);
        }
        makeBalance();
    }

    void erase(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    double getMedian() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }
};

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualHeap dh(k);
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            dh.insert(nums[i]);
        }
        vector<double> ans = {dh.getMedian()};
        for (int i = k; i < n; ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.emplace_back(dh.getMedian());
        }
        return ans;
    }
};
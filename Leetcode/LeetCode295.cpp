// 数据流的中位数
#include <queue>
#include <vector>
using namespace std;

//解法1: 始终保持列表有序 耗时380ms
//插入时使用二分查找lower_bound在第一个大于等于num的位置插入
class MedianFinder {
   public:
    vector<int> v;
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (v.empty())
            v.push_back(num);
        else {
            v.insert(lower_bound(v.begin(), v.end(), num), num);
        }
    }

    double findMedian() {
        int n = v.size();
        return n & 1 ? v[n >> 1] : (v[n >> 1] + v[n / 2 - 1]) * 0.5;
    }
};

//解法2: 维护一个大顶堆与小顶堆 中位数即为大堆堆顶或两堆堆顶加和除2
//大顶堆放较小数字（列表前一半），小顶堆放较大数字（列表后一半）
//两堆大小必须平衡：大小相等或大顶堆（较小数字堆）比小顶堆大小多一
class MedianFinder2 {
   public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    /** initialize your data structure here. */
    MedianFinder2() {}

    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        int n = small.size() + large.size();
        return n & 1 ? small.top() : (small.top() + large.top()) * 0.5;
    }
};
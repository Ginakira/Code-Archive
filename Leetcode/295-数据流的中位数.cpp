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
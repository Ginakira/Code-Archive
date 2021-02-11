// 数据流中的第K大元素
#include <cstdlib>
#include <queue>
#include <set>
#include <vector>
using namespace std;

//解法1: 使用优先队列维护一个始终递增序列（数值小的优先极高）
//优先队列的尺寸始终保持为k 这样队首元素就正好是第k大的元素
class KthLargest {
   public:
    KthLargest(int _k, vector<int> &nums) : k(_k) {
        for (const int &num : nums) {
            this->add(num);
        }
    }

    int add(int val) {
        if (heap.size() < k || val > heap.top()) {
            heap.push(val);
        }
        if (heap.size() > k) {
            heap.pop();
        }
        return heap.top();
    }

   private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
};

//解法2: 使用STL-set中的multiset，自动维护一个递增的序列
//不同于set的是，multiset中的元素可以重复，插入与删除时间效率均为O(logn)
class KthLargest2 {
   public:
    int size_k;
    multiset<int> s;
    KthLargest2(int k, vector<int> &nums) {
        size_k = k;
        for (auto i : nums) {
            add(i);
        }
    }

    int add(int val) {
        s.insert(val);
        if (s.size() > size_k) s.erase(s.begin());
        return *s.begin();
    }
};

//手写小顶堆
class KthLargest3 {
   public:
    int *heap_data;
    int heap_size, heap_cnt, size_k;

    KthLargest3(int k, vector<int> &nums) {
        heap_data = (int *)malloc(sizeof(int) * (k + 1));
        heap_size = k, heap_cnt = 0, size_k = k;
        for (int i : nums) {
            add(i);
        }
    }

    int heap_top(int *data) { return data[1]; }

    int update(int *data, int ind, int n) {
        while ((ind << 1) <= n) {
            int cur_min = ind, left = ind << 1, right = ind << 1 | 1;
            if (data[left] < data[cur_min]) cur_min = left;
            if (right <= n && data[right] < data[cur_min]) cur_min = right;
            if (cur_min == ind) break;
            swap(data[cur_min], data[ind]);
            ind = cur_min;
        }
        return 1;
    }

    int heap_push(int *data, int val) {
        if (heap_cnt == heap_size) return 0;
        data[++heap_cnt] = val;
        int ind = heap_cnt;
        while (ind >> 1 && data[ind] < data[ind >> 1]) {
            swap(data[ind], data[ind >> 1]);
            ind >>= 1;
        }
        return 1;
    }

    int heap_pop(int *data) {
        if (heap_cnt == 0) return 0;
        data[1] = data[heap_cnt--];
        update(data, 1, heap_cnt);
        return 1;
    }

    int add(int val) {
        if (heap_cnt < size_k) {
            heap_push(heap_data, val);
        } else if (val > heap_top(heap_data)) {
            heap_pop(heap_data);
            heap_push(heap_data, val);
        }
        return heap_top(heap_data);
    }
};
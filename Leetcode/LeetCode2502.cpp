// LeetCode 2502 设计内存分配器

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Allocator {
   private:
    vector<int> mem_;
    int n_;

   public:
    Allocator(int n) : n_(n), mem_(n, 0) {}

    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < n_; ++i) {
            if (mem_[i]) {
                cnt = 0;
                continue;
            }
            ++cnt;
            if (cnt == size) {
                for (int j = i - cnt + 1; j <= i; ++j) {
                    mem_[j] = mID;
                }
                return i - cnt + 1;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int cnt = 0;
        for (int i = 0; i < n_; ++i) {
            if (mem_[i] != mID) {
                continue;
            }
            ++cnt;
            mem_[i] = 0;
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
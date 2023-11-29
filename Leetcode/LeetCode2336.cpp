// LeetCode 2336 无限集中的最小数字

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

class SmallestInfiniteSet {
   private:
    std::set<int> selectable;
    int current = 1;

   public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        int ret = 0;
        if (!selectable.empty()) {
            ret = *selectable.begin();
            selectable.erase(selectable.begin());
        } else {
            ret = current;
            ++current;
        }
        return ret;
    }

    void addBack(int num) {
        if (num >= current) {
            return;
        }
        selectable.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

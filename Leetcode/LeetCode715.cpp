// LeetCode 715 Range模块

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class RangeModule {
   private:
    map<int, int> sections;

   public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = sections.upper_bound(left);
        if (it != sections.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                sections.erase(start);
            }
        }
        while (it != sections.end() && it->first <= right) {
            right = max(right, it->second);
            it = sections.erase(it);
        }
        sections[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = sections.upper_bound(left);
        if (it == sections.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }

    void removeRange(int left, int right) {
        auto it = sections.upper_bound(left);
        if (it != sections.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ss = start->second;
                if (start->first == left) {
                    sections.erase(start);
                } else {
                    start->second = left;
                }
                if (right != ss) {
                    sections[right] = ss;
                }
                return;
            } else if (start->second > left) {
                start->second = left;
            }
        }
        while (it != sections.end() && it->first < right) {
            if (it->second <= right) {
                it = sections.erase(it);
            } else {
                sections[right] = it->second;
                sections.erase(it);
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
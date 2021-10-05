// LeetCode 284 窥探迭代器

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Iterator {
    struct Data;
    Data* data;

   public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
   private:
    int next_element;
    bool remain_element;

   public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        remain_element = Iterator::hasNext();
        if (remain_element) {
            next_element = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return next_element; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = next_element;
        remain_element = Iterator::hasNext();
        if (remain_element) {
            next_element = Iterator::next();
        }
        return ret;
    }

    bool hasNext() const { return remain_element; }
};
// LeetCode 341 扁平化嵌套列表迭代器

#include <vector>
using namespace std;
class NestedInteger;
// S1 DFS
class NestedIterator {
   private:
    vector<int> _data;
    int _pos = 0;

    void dfs(const vector<NestedInteger> &list) {
        for (const auto &elem : list) {
            if (elem.isInteger()) {
                _data.emplace_back(elem.getInteger());
            } else {
                dfs(elem.getList());
            }
        }
        return;
    }

   public:
    NestedIterator(vector<NestedInteger> &nestedList) { dfs(nestedList); }

    int next() { return _data[_pos++]; }

    bool hasNext() { return _pos < _data.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
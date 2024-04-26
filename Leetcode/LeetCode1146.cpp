// LeetCode 1146 快照数组

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

class SnapshotArray {
   private:
    int snap_id_ = 0;
    vector<vector<pair<int, int>>> data;

   public:
    SnapshotArray(int length) : data(length) {}

    void set(int index, int val) { data[index].emplace_back(snap_id_, val); }

    int snap() { return snap_id_++; }

    int get(int index, int snap_id) {
        auto x = upper_bound(data[index].begin(), data[index].end(),
                             pair{snap_id + 1, -1});
        return x == data[index].begin() ? 0 : prev(x)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
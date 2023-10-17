// LeetCode 1993 树上的操作

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

class LockingTree {
   private:
    vector<int> parent_;
    vector<vector<int>> children_;
    vector<int> locker_;

    bool HasLockedAncestor(int num) {
        auto p = parent_[num];
        while (p != -1) {
            if (locker_[p] != -1) {
                return true;
            }
            p = parent_[p];
        }
        return false;
    }

    bool CheckAndUnlockDescendant(int num) {
        bool has_locked_node = locker_[num] != -1;
        locker_[num] = -1;
        for (int child : children_[num]) {
            has_locked_node |= CheckAndUnlockDescendant(child);
        }
        return has_locked_node;
    }

   public:
    LockingTree(vector<int> &parent) : parent_(parent) {
        size_t n = parent_.size();
        children_.resize(n);
        locker_.resize(n, -1);
        for (size_t i = 0; i < n; ++i) {
            int p = parent_[i];
            if (p != -1) {
                children_[p].emplace_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (locker_[num] != -1) {
            return false;
        }
        locker_[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (user != locker_[num]) {
            return false;
        }
        locker_[num] = -1;
        return true;
    }

    bool upgrade(int num, int user) {
        bool valid = locker_[num] == -1 && !HasLockedAncestor(num) &&
                     CheckAndUnlockDescendant(num);
        if (valid) {
            locker_[num] = user;
        }
        return valid;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

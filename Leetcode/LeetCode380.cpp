// LeetCode 380 O(1)时间插入、删除和获取随机元素

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
   private:
    unordered_map<int, int> val_to_ind_;
    vector<int> nums;

   public:
    RandomizedSet() { srand(time(0)); }

    bool insert(int val) {
        if (val_to_ind_.find(val) != val_to_ind_.end()) {
            return false;
        }
        val_to_ind_[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (val_to_ind_.find(val) == val_to_ind_.end()) {
            return false;
        }
        int del_index = val_to_ind_[val];
        int last_num = nums.back();
        nums[del_index] = last_num;
        val_to_ind_[last_num] = del_index;
        nums.pop_back();
        val_to_ind_.erase(val);
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// LeetCode 677 键值映射

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MapSum {
   private:
    unordered_map<string, int> mp;
    unordered_map<string, int> seen;

   public:
    MapSum() {}

    void insert(string key, int val) {
        int diff_val = val;
        if (seen.count(key)) {
            diff_val = val - seen[key];
        }
        seen[key] = val;
        string pre_key;
        for (char c : key) {
            pre_key.push_back(c);
            mp[pre_key] += diff_val;
        }
    }

    int sum(string prefix) { return mp[prefix]; }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// LeetCode 981 基于时间的键值存储

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &pairs = mp[key];
        pair<int, string> tp{timestamp, {127}};
        auto it = upper_bound(pairs.begin(), pairs.end(), tp);
        if (it != pairs.begin()) {
            return (it - 1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
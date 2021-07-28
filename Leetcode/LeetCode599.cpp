// LeetCode 599 两个列表的最小索引总和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); ++i) {
            mp[list1[i]] = i;
        }

        int min_sum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size(); ++i) {
            if (mp.find(list2[i]) == mp.end()) continue;
            int sum = i + mp[list2[i]];
            if (sum < min_sum) {
                ans.clear();
                ans.push_back(list2[i]);
                min_sum = sum;
            } else if (sum == min_sum) {
                ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};
// LeetCode 1604 警告一小时内使用相同员工卡大于等于三次的人

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> alertNames(vector<string>& keyName,
                              vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;
        int n = keyName.size();
        for (int i = 0; i < n; ++i) {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            mp[name].emplace_back(hour * 60 + minute);
        }
        vector<string> ans;
        for (auto& [name, timelist] : mp) {
            sort(timelist.begin(), timelist.end());
            int timelist_n = timelist.size();
            for (int i = 2; i < timelist_n; ++i) {
                int time_a = timelist[i - 2], time_b = timelist[i];
                if (time_b - time_a <= 60) {
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
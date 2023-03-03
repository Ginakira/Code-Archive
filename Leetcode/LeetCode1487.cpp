// LeetCode 1487 保证文件名唯一

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (auto& name : names) {
            string folder_name = name;
            if (mp.count(folder_name)) {
                int k = mp[name];
                do {
                    folder_name = name + "(" + std::to_string(k) + ")";
                    ++k;
                } while (mp.count(folder_name));
                mp[name] = k;
            }
            mp[folder_name] = 1;
            ans.emplace_back(folder_name);
        }
        return ans;
    }
};
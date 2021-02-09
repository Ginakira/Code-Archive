// LeetCode 71 简化路径
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string s;
        vector<string> strs;
        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            } else if (s == "..") {
                if (!strs.empty()) strs.pop_back();
            } else {
                strs.push_back(s);
            }
        }
        string ans;
        for (const auto &str : strs) {
            ans += '/' + str;
        }
        return ans.size() ? ans : "/";
    }
};
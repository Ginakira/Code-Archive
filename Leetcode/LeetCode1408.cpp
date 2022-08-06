 // LeetCode 1408 数组中的字符串匹配

 #include <algorithm>
 #include <numeric>
 #include <unordered_map>
 #include <string>
 #include <vector>
 using namespace std;

 class Solution {
    public:
     vector<string> stringMatching(vector<string>& words) {
         vector<string> ans;
         int n = words.size();
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < n; ++j) {
                 if (i != j && words[j].find(words[i]) != string::npos) {
                     ans.emplace_back(words[i]);
                     break;
                 }
             }
         }
         return ans;
     }
 };
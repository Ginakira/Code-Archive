// LeetCode 2418 按身高排序

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

class Solution {
   public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> height_names(n);
        for (int i = 0; i < n; ++i) {
            height_names[i] = make_pair(heights[i], names[i]);
        }
        sort(height_names.begin(), height_names.end(),
             greater<pair<int, string>>());
        transform(height_names.begin(), height_names.end(), names.begin(),
                  [](auto p) { return p.second; });
        return names;
    }
};

class Solution2 {
   public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&heights](auto a, auto b) { return heights[a] > heights[b]; });
        vector<string> ans(n);
        transform(indices.begin(), indices.end(), ans.begin(),
                  [&names](auto ind) { return names[ind]; });
        return ans;
    }
};
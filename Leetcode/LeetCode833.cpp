// LeetCode 833 字符串中的查找与替换

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
    string findReplaceString(string s, vector<int>& indices,
                             vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        std::vector<int> ind(n);
        std::iota(ind.begin(), ind.end(), 0);
        std::sort(ind.begin(), ind.end(), [&indices](auto& a, auto& b) {
            return indices[a] < indices[b];
        });
        std::string result;
        int s_ind = 0;
        for (auto& i : ind) {
            auto index = indices[i];
            auto source = sources[i];
            auto target = targets[i];
            while (s_ind < index) {
                result.push_back(s[s_ind]);
                ++s_ind;
            }
            if (s.substr(index, source.size()) == source) {
                result += target;
                s_ind += source.size();
            }
        }
        for (; s_ind < s.size(); ++s_ind) {
            result.push_back(s[s_ind]);
        }
        return result;
    }
};

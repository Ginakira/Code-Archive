// LeetCode 2766 重新放置石块

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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom,
                                vector<int>& moveTo) {
        set<int> st(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); ++i) {
            int from = moveFrom[i], to = moveTo[i];
            st.erase(from);
            st.insert(to);
        }
        return vector<int>(st.begin(), st.end());
    }
};
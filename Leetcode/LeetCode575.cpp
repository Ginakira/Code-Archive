// LeetCode 575 分糖果

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for (const int& type : candyType) {
            st.insert(type);
        }
        return min(st.size(), candyType.size() / 2);
    }
};
// LeetCode 406 根据身高重建队列
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(),
             [](const vector<int> &a, const vector<int> &b) -> bool {
                 return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        vector<vector<int>> ans;
        for (auto &person : people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};
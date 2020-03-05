// 分糖果 II
#include <vector>
using namespace std;

// 模拟
class Solution {
   public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int now = 1, ind = 0;
        while (candies >= now) {
            ans[ind] += now;
            ind = (ind + 1) % num_people;
            candies -= now, now++;
        }
        ans[ind] += candies;
        return ans;
    }
};
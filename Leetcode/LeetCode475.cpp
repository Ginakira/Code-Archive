// LeetCode 475 供暖器

#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            int right_ind = upper_bound(heaters.begin(), heaters.end(), house) -
                            heaters.begin();
            int left_ind = right_ind - 1;
            int left_dis = left_ind < 0 ? INT_MAX : house - heaters[left_ind];
            int right_dis = right_ind >= heaters.size()
                                ? INT_MAX
                                : heaters[right_ind] - house;
            ans = max(min(left_dis, right_dis), ans);
        }
        return ans;
    }
};
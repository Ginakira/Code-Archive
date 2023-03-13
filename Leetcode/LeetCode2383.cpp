// LeetCode 2383 赢得比赛需要的最少训练时长

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int> &energy, vector<int> &experience) {
        int ans = 0;
        int cur_energy = initialEnergy, cur_exp = initialExperience;
        auto helper = [](vector<int> &arr, int &current, int &result, auto op) {
            for (auto e : arr) {
                if (e >= current) {
                    result += e - current + 1;
                    current = e + 1;
                }
                current = op(current, e);
            }
        };
        helper(energy, cur_energy, ans, std::minus{});
        helper(experience, cur_exp, ans, std::plus{});
        return ans;
    }
};
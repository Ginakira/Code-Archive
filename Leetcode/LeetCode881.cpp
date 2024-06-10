// LeetCode 881 救生艇

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        ranges::sort(people, std::greater());
        int res = 0;
        for (int l = 0, r = n - 1; l <= r; ++l) {
            if (people[l] + people[r] <= limit) {
                --r;
            }
            ++res;
        }
        return res;
    }
};
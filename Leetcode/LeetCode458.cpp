// LeetCode 458 可怜的小猪

#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int chances = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(chances));
    }
};
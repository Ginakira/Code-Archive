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
        unordered_set<int> us(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, us.size());
    }
};
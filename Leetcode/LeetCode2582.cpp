// LeetCode 2582 递枕头

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
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        return time < n ? time + 1 : n - (time - (n - 1));
    }
};
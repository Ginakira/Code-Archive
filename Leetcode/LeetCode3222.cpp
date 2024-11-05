// LeetCode 3222 求出硬币游戏的赢家

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
    string losingPlayer(int x, int y) {
        return min(x, y / 4) & 1 ? "Alice" : "Bob";
    }
};
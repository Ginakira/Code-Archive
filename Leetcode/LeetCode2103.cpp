// LeetCode 2103 环和杆

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
    int countPoints(string rings) {
        int n = rings.size() / 2;
        constexpr static int RED = 0x1, GREEN = 0x10, BLUE = 0x100, ALL = 0x111;
        std::array<int, 10> mark{0};
        for (int i = 0; i < rings.size(); i += 2) {
            char color = rings[i];
            int num = rings[i + 1] - '0';
            switch (color) {
                case 'R':
                    mark[num] |= RED;
                    break;
                case 'G':
                    mark[num] |= GREEN;
                    break;
                case 'B':
                    mark[num] |= BLUE;
                    break;
                default: {
                }
            }
        }
        return count_if(mark.begin(), mark.end(),
                        [](const auto &item) { return (item & ALL) == ALL; });
    }
};

// 面试题 17.11. 单词距离

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int ind_1 = -1, ind_2 = -1;
        int min_dis = INT_MAX;
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                ind_1 = i;
            } else if (words[i] == word2) {
                ind_2 = i;
            }
            if (ind_1 != -1 && ind_2 != -1) {
                min_dis = min(min_dis, abs(ind_1 - ind_2));
            }
        }
        return min_dis;
    }
};
// LeetCode 682 棒球比赛

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int calPoints(vector<string>& ops) {
        int total = 0;
        vector<int> scores;
        for (auto& op : ops) {
            size_t n = scores.size();
            switch (op[0]) {
                case '+': {
                    total += scores[n - 1] + scores[n - 2];
                    scores.push_back(scores[n - 1] + scores[n - 2]);
                    break;
                }
                case 'D': {
                    total += scores[n - 1] * 2;
                    scores.push_back(scores[n - 1] * 2);
                    break;
                }
                case 'C': {
                    total -= scores[n - 1];
                    scores.pop_back();
                    break;
                }
                default: {
                    int num = stoi(op);
                    total += num;
                    scores.push_back(num);
                    break;
                }
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
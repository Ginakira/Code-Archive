// LeetCode 682 棒球比赛

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
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

class Solution2 {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        records.reserve(operations.size());
        for (string op : operations) {
            if (op[0] == 'C') {
                records.pop_back();
            } else if (op[0] == 'D') {
                records.emplace_back(records.back() * 2);
            } else if (op[0] == '+') {
                records.emplace_back(records[records.size() - 1] +
                                     records[records.size() - 2]);
            } else {
                records.emplace_back(stoi(op));
            }
        }
        return accumulate(records.begin(), records.end(), 0);
    }
};
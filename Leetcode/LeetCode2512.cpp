// LeetCode 2512 奖励最顶尖的K名学生

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {
        unordered_set<string> positive_dict(positive_feedback.begin(),
                                            positive_feedback.end());
        unordered_set<string> negative_dict(negative_feedback.begin(),
                                            negative_feedback.end());

        vector<pair<int, int>> score_ids;
        score_ids.reserve(student_id.size());
        for (int i = 0; i < report.size(); ++i) {
            auto& r = report[i];
            stringstream ss(r);
            string word;
            int score = 0;
            while (ss >> word) {
                if (positive_dict.count(word)) {
                    score += 3;
                } else if (negative_dict.count(word)) {
                    --score;
                }
            }
            score_ids.emplace_back(score, -student_id[i]);
        }
        sort(score_ids.rbegin(), score_ids.rend());
        vector<int> tops;
        tops.resize(k);
        transform(score_ids.begin(), score_ids.begin() + k, tops.begin(),
                  [](auto& p) { return -p.second; });
        return tops;
    }
};
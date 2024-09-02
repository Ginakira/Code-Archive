// LeetCode 2024 考试的最大困扰度

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int maxConsecutiveAnswers(const string &answerKey, char key, int k) {
        size_t not_key_count = 0, max_ans = 0;
        size_t n = answerKey.size(), left = 0, right = 0;
        while (right < n) {
            not_key_count += answerKey[right] != key;
            while (not_key_count > k) {
                not_key_count -= answerKey[left] != key;
                ++left;
            }
            ++right;
            max_ans = max(max_ans, right - left);
        }
        return max_ans;
    }

   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveAnswers(answerKey, 'T', k),
                   maxConsecutiveAnswers(answerKey, 'F', k));
    }
};


class Solution2 {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto helper = [&](char target) {
            int n = answerKey.size();
            int ans = 0;
            for (int l = 0, r = 0, cnt = 0; r < n; ++r) {
                cnt += answerKey[r] != target;
                while (cnt > k) {
                    cnt -= answerKey[l++] != target;
                }
                ans = max(ans, r - l + 1);
            }
            return ans;
        };
        return max(helper('T'), helper('F'));
    }
};
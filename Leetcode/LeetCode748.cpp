// LeetCode 748 最短补全词

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> freq{};
        for (char c : licensePlate) {
            if (!isalpha(c)) continue;
            freq[tolower(c) - 'a']++;
        }

        int ind = -1;
        for (int i = 0; i < words.size(); ++i) {
            array<int, 26> word_freq{};
            for (char c : words[i]) {
                word_freq[tolower(c) - 'a']++;
            }

            bool valid = true;
            for (int j = 0; j < 26; ++j) {
                if (word_freq[j] < freq[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid && (ind == -1 || words[i].size() < words[ind].size())) {
                ind = i;
            }
        }
        return words[ind];
    }
};
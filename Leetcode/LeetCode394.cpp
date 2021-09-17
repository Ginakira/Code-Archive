// LeetCode 394 字符串解码

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int get_number(const string &s, size_t &ind) {
        int num = 0;
        while (isdigit(s[ind])) {
            num = num * 10 + s[ind] - '0';
            ++ind;
        }
        return num;
    }

    string join_string(const vector<string> &vec) {
        string result;
        for (const auto &s : vec) {
            result += s;
        }
        return result;
    }

   public:
    string decodeString(string s) {
        size_t n = s.size();
        size_t ind = 0;
        vector<string> stk;
        while (ind < n) {
            if (isdigit(s[ind])) {
                int number = get_number(s, ind);
                stk.emplace_back(to_string(number));
            } else if (isalpha(s[ind]) || s[ind] == '[') {
                stk.emplace_back(string(1, s[ind]));
                ++ind;
            } else if (s[ind] == ']') {
                ++ind;
                vector<string> vec;
                while (stk.back() != "[") {
                    vec.emplace_back(stk.back());
                    stk.pop_back();
                }
                reverse(vec.begin(), vec.end());
                string str = join_string(vec);

                stk.pop_back();  // '['
                int repeat_count = stoi(stk.back());
                stk.pop_back();

                string repeated;
                for (int i = 0; i < repeat_count; ++i) {
                    repeated += str;
                }
                stk.push_back(repeated);
            }
        }
        return join_string(stk);
    }
};
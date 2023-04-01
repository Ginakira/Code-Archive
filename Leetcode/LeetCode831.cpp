// LeetCode 831 隐藏个人信息

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    string process_email_addr(const string &s, size_t at_ind) {
        string ans;
        ans += tolower(s[0]);
        ans += string(5, '*');
        ans += tolower(s[at_ind - 1]);
        ans += '@';
        transform(next(s.begin(), at_ind + 1), s.end(), std::back_inserter(ans),
                  ::tolower);
        return ans;
    }

    string process_phone_number(const string &s) {
        string s_processed;
        for (auto ch : s) {
            if (ch == '+' || ch == '-' || ch == '(' || ch == ')' || ch == ' ') {
                continue;
            }
            s_processed.push_back(ch);
        };
        string ans;
        if (s_processed.size() > 10) {
            ans += '+';
            ans += string(s_processed.size() - 10, '*') + '-';
        }
        ans += "***-***-";
        ans += s_processed.substr(s_processed.size() - 4);
        return ans;
    }

   public:
    string maskPII(string s) {
        auto at_ind = s.find('@');
        if (at_ind != string::npos) {
            return process_email_addr(s, at_ind);
        } else {
            return process_phone_number(s);
        }
        return {};
    }
};
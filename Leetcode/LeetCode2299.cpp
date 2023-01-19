// LeetCode 2299 强密码检验器II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool strongPasswordCheckerII(string password) {
        auto length_checker = [](string &password) -> bool {
            return password.size() >= 8;
        };
        auto lower_case_checker = [](string &password) -> bool {
            return any_of(password.begin(), password.end(),
                          [](auto &ch) { return islower(ch); });
        };
        auto upper_case_checker = [](string &password) -> bool {
            return any_of(password.begin(), password.end(),
                          [](auto &ch) { return isupper(ch); });
        };
        auto digits_checker = [](string &password) -> bool {
            return any_of(password.begin(), password.end(),
                          [](auto &ch) { return isdigit(ch); });
        };
        auto special_character_checker = [](string &password) -> bool {
            return any_of(password.begin(), password.end(), [](auto &ch) {
                return ch == '!' || ch == '@' || ch == '#' || ch == '$' ||
                       ch == '%' || ch == '^' || ch == '&' || ch == '&' ||
                       ch == '*' || ch == '(' || ch == ')' || ch == '-' ||
                       ch == '+';
            });
        };
        auto continuous_identical_checker = [](string &password) -> bool {
            size_t n = password.size();
            for (size_t i = 1; i < n; ++i) {
                if (password[i] == password[i - 1]) {
                    return false;
                }
            }
            return true;
        };
        vector<function<bool(string &)>> rules{
            length_checker,
            lower_case_checker,
            upper_case_checker,
            digits_checker,
            special_character_checker,
            continuous_identical_checker,
        };
        return all_of(rules.begin(), rules.end(),
                      [&](auto &rule) { return rule(password); });
    }
};
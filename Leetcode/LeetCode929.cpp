// LeetCode 929 独特的电子邮件地址

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<std::string> us;
        for (const auto& email : emails) {
            string real_email;
            for (size_t ind = 0; ind < email.size(); ++ind) {
                if (email[ind] == '@' || email[ind] == '+') {
                    break;
                }
                if (email[ind] == '.') {
                    continue;
                }
                real_email.push_back(email[ind]);
            }
            real_email += email.substr(email.find("@"));
            us.insert(real_email);
        }
        return us.size();
    }
};
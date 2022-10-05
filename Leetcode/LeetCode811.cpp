// LeetCode 811 子域名访问计数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> domain_to_cnt;
        for (auto &cpdomain : cpdomains) {
            auto blank_pos = cpdomain.find(" ");
            int count = stoi(cpdomain.substr(0, blank_pos + 1));
            string full_domain = cpdomain.substr(blank_pos + 1);
            while (!full_domain.empty()) {
                domain_to_cnt[full_domain] += count;
                auto pos = full_domain.find(".");
                if (pos == string::npos) {
                    break;
                }
                full_domain.erase(0, pos + 1);
            }
        }

        vector<string> result;
        for (auto &[domain, count] : domain_to_cnt) {
            result.emplace_back(to_string(count) + " " + domain);
        }
        return result;
    }
};
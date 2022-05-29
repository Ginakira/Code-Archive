// LeetCode 468 验证 IP 地址

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool is_valid_ipv4(const string &ip) {
        if (ip.find('.') == string::npos) {
            return false;
        }
        int last_pos = -1;
        for (size_t i = 0; i < 4; ++i) {
            size_t cur_pos = (i == 3 ? ip.size() : ip.find('.', last_pos + 1));
            if (cur_pos == string::npos || cur_pos - last_pos - 1 < 1 ||
                cur_pos - last_pos - 1 > 3) {
                return false;
            }
            int seg = 0;
            for (size_t j = last_pos + 1; j < cur_pos; ++j) {
                if (!isdigit(ip[j])) {
                    return false;
                }
                seg = seg * 10 + ip[j] - '0';
            }
            if (seg > 255) {
                return false;
            }
            if (seg != 0 && ip[last_pos + 1] == '0') {
                return false;
            }
            if (seg == 0 && cur_pos - last_pos - 1 > 1) {
                return false;
            }
            last_pos = cur_pos;
        }
        return true;
    }

    bool is_valid_ipv6(const string &ip) {
        if (ip.find(':') == string::npos) {
            return false;
        }
        int last_pos = -1;
        for (size_t i = 0; i < 8; ++i) {
            size_t cur_pos = (i == 7 ? ip.size() : ip.find(':', last_pos + 1));
            if (cur_pos == string::npos || cur_pos - last_pos - 1 < 1 ||
                cur_pos - last_pos - 1 > 4) {
                return false;
            }
            for (size_t j = last_pos + 1; j < cur_pos; ++j) {
                char ch = ip[j];
                if (!isdigit(ch) && (ch < 'a' || ch > 'f') &&
                    (ch < 'A' || ch > 'F')) {
                    return false;
                }
            }
            last_pos = cur_pos;
        }
        return true;
    }

   public:
    string validIPAddress(string queryIP) {
        if (is_valid_ipv4(queryIP)) {
            return "IPv4";
        } else if (is_valid_ipv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }
};
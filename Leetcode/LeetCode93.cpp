// LeetCode 93 复原IP地址

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    constexpr static int SEG_COUNT = 4;
    int n;
    vector<int> segment;
    vector<string> result;

    string join_str() {
        string s;
        for (int i = 0; i < 4; ++i) {
            if (i != 0) {
                s.push_back('.');
            }
            s += to_string(segment[i]);
        }
        return s;
    }

    void backtrace(const string &s, int ind, int seg_id) {
        if (seg_id == SEG_COUNT) {
            if (ind == n) {
                result.emplace_back(join_str());
                return;
            }
            return;
        }
        if (ind == n) {
            return;
        }

        if (s[ind] == '0') {
            segment[seg_id] = 0;
            backtrace(s, ind + 1, seg_id + 1);
            return;
        }

        int sum = 0;
        for (int i = ind; i < n; ++i) {
            sum = sum * 10 + s[i] - '0';
            if (sum <= 0xff) {
                segment[seg_id] = sum;
                backtrace(s, i + 1, seg_id + 1);
            } else {
                break;
            }
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        segment.resize(SEG_COUNT, 0);
        backtrace(s, 0, 0);
        return result;
    }
};
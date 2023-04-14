// LeetCOde 1023 驼峰式匹配

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        const size_t n = queries.size();
        const size_t pn = pattern.size();
        vector<bool> result;
        result.reserve(n);
        for (const auto& query : queries) {
            size_t pq = 0, pp = 0, qn = query.size();
            bool res = true;
            while (pp < pn) {
                while (pq < qn && islower(query[pq]) &&
                       (isupper(pattern[pp]) || query[pq] != pattern[pp])) {
                    // pattern当前大写、query当前小写：p_query前进
                    // pattern当前小写、query当前小写：p_query前进（尝试在query匹配下一个和pattern当前小写一样的字母）
                    // pattern当前大写、query当前大写：跳出移动p_query的循环，直接判断
                    // pattern当前小写、query当前大写：跳出移动p_query的循环，直接判断
                    ++pq;
                }
                if (pq == qn || pattern[pp] != query[pq]) {
                    res = false;
                    break;
                }
                ++pp, ++pq;
            }
            while (res &&
                   pq < qn) {  // pattern匹配完后，query剩余字符必须全为小写
                if (isupper(query[pq])) {
                    res = false;
                    break;
                }
                ++pq;
            }
            result.emplace_back(res);
        }
        return result;
    }
};
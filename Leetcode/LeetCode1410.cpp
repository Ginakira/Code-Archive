// LeetCode 1410 HTML实体解析器

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
    using EntityChar = pair<string, char>;

    string entityParser(string text) {
        const static std::array<EntityChar, 6> entities{{
            {"&quot;", '"'},
            {"&apos;", '\''},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'},
        }};

        string result{};
        for (int pos = 0; pos < text.size();) {
            bool is_entity = false;
            if (text[pos] == '&') {
                for (const auto &[src, dst] : entities) {
                    if (text.substr(pos, src.size()) == src) {
                        result.push_back(dst);
                        pos += src.size();
                        is_entity = true;
                        break;
                    }
                }
            }
            if (!is_entity) {
                result.push_back(text[pos++]);
                continue;
            }
        }
        return result;
    }
};
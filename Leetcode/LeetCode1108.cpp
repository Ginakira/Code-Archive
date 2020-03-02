// IP 地址无效化
#include <string>
using namespace std;

class Solution {
   public:
    string defangIPaddr(string address) {
        string s = address, src = ".", target = "[.]";
        size_t pos = 0, src_len = src.size(), target_len = target.size();
        while ((pos = s.find(src, pos)) != string::npos) {
            s.replace(pos, src_len, target);
            pos += target_len;
        }
        return s;
    }
};
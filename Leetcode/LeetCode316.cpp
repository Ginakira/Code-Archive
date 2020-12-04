// LeetCode 316 取出重复字母
#include <map>
#include <set>
#include <stack>
#include <string>
using namespace std;

// Solution1: 单调栈 27ms
class Solution1 {
   public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        stack<char> st;
        set<char> seen;
        for (auto &c : s) {
            mp[c]++;
        }

        for (auto &c : s) {
            if (seen.find(c) == seen.end()) {
                while (!st.empty() && st.top() > c && mp[st.top()] > 0) {
                    seen.erase(st.top());
                    st.pop();
                }
                st.push(c);
                seen.insert(c);
            }
            --mp[c];
        }

        string ret = "";
        while (!st.empty()) {
            ret = st.top() + ret;
            st.pop();
        }
        return ret;
    }
};

// Solution2: 使用结果字符串代替栈 大幅节省时间 0ms
class Solution2 {
   public:
    string removeDuplicateLetters(string s) {
        string ret;
        for (size_t i = 0; i < s.size(); ++i) {
            if (ret.find(s[i]) != string::npos) continue;
            while (!ret.empty() && s[i] < ret.back() &&
                   s.find(ret.back(), i) != string::npos) {
                ret.pop_back();
            }
            ret.push_back(s[i]);
        }
        return ret;
    }
};
// 删除字符串中的所有相邻重复项
#include <deque>
#include <string>
using namespace std;

// 使用deque双端队列模拟栈 如果当前字母与栈顶相同则弹出 否则将当前字母入栈
class Solution {
   public:
    string removeDuplicates(string S) {
        deque<char> dq;
        for (char c : S) {
            if (!dq.empty() && c == dq.back())
                dq.pop_back();
            else
                dq.push_back(c);
        }
        string ret = "";
        for (char c : dq) ret += c;
        return ret;
    }
};

// 直接使用string代替栈
class Solution2 {
   public:
    string removeDuplicates(string S) {
        string ret;
        for (char &c : S) {
            if (ret.size() && ret.back() == c) {
                ret.pop_back();
                continue;
            }
            ret.push_back(c);
        }
        return ret;
    }
};
#include <deque>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 83.33%
string decodeString(string str) {
    if (str.empty()) return {};
    int n = str.size();
    string result;
    int ind = 0;
    deque<string> stk;
    while (ind < n) {
        char ch = str[ind];
        if (ch >= '0' && ch <= '9') {
            int count = 0;
            while (ind < n && str[ind] >= '0' && str[ind] <= '9') {
                count = count * 10 + str[ind] - '0';
                ++ind;
            }
            stk.push_back(to_string(count));
        } else if (ch == '[') {
            stk.push_back("[");
            stk.emplace_back();
            ++ind;
        } else if (ch == ']') {
            string sub_str;
            int sub_cnt = 0;
            while (stk.back() != "[") {
                sub_str += stk.back();
                stk.pop_back();
                ++sub_cnt;
            }
            if (sub_cnt > 1) {
                reverse(sub_str.begin(), sub_str.end());
            }
            stk.pop_back();
            if (stk.back() != "[" && !stk.back().empty()) {
                string result;
                int repeat_count = stoi(stk.back());
                stk.pop_back();
                for (int i = 0; i < repeat_count; ++i) {
                    result += sub_str;
                }
                stk.push_back(result);
            }
            ++ind;
        } else {
            stk.push_back(string(1, ch));
            ++ind;
        }
    }

    string ret;
    for (auto &e : stk) {
        ret += e;
    }
    return ret;
}

int main() {
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;
    cout << decodeString("abc3[cd]xyz") << endl;
    cout << decodeString("abcdag21[a]") << endl;
    cout << decodeString("a2[b3[c]3[dgh]e]f") << endl;
    return 0;
}
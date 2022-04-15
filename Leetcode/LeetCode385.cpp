// LeetCode 385 迷你语法分析器

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to
    // it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
   public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        int current_number = 0;
        int negtive_flag = 1;
        stack<NestedInteger> stk;
        size_t ind = 0, len = s.size();

        while (ind < len) {
            char ch = s[ind];
            if (ch == '-') {
                negtive_flag = -1;
            } else if (isdigit(ch)) {
                current_number = current_number * 10 + ch - '0';
            } else if (ch == '[') {
                stk.emplace();
            } else if (ch == ',' || ch == ']') {
                if (isdigit(s[ind - 1])) {
                    stk.top().add(NestedInteger(current_number * negtive_flag));
                    negtive_flag = 1;
                    current_number = 0;
                }
                if (ch == ']' && stk.size() > 1) {
                    auto element = stk.top();
                    stk.pop();
                    stk.top().add(element);
                }
            }
            ++ind;
        }
        return stk.top();
    }
};
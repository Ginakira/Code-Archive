// LeetCode 331 验证二叉树的前序序列化
#include <stack>
#include <string>
using namespace std;

// 槽位思想：
// 一个数字节点需要2个槽位进行填充（槽位+2）
// 一个#空节点消耗一个槽位（槽位-1）
class Solution {
   public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        stack<int> stk;
        stk.push(1);
        while (i < n) {
            if (stk.empty()) {
                return false;
            }
            if (preorder[i] == ',') {
                ++i;
            } else if (preorder[i] == '#') {
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                ++i;
            } else {
                while (i < n && preorder[i] != ',') ++i;
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                stk.push(2);
                ++i;
            }
        }
        return stk.empty();
    }
};

// 无需栈 可以将槽位累计统计

class Solution2 {
   public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        int slots = 1;
        while (i < n) {
            if (slots == 0) {
                return false;
            }
            if (preorder[i] == ',') {
                ++i;
            } else if (preorder[i] == '#') {
                --slots;
                ++i;
            } else {
                while (i < n && preorder[i] != ',') ++i;
                ++slots;
                ++i;
            }
        }
        return slots == 0;
    }
};

class Solution3 {
   public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string cur;
        stack<int> stk;
        stk.emplace(1);
        while (getline(ss, cur, ',')) {
            if (stk.empty()) {
                return false;
            }
            --stk.top();
            if (stk.top() == 0) {
                stk.pop();
            }
            if (cur[0] != '#') {
                stk.push(2);
            }
        }
        return stk.empty();
    }
};
// AC
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a ListNode类vector 指向这些数链的开头
     * @return ListNode类
     */
    ListNode *solve(vector<ListNode *> &a) {
        ListNode _dummy(-1), *dummy = &_dummy;
        ListNode *cur = dummy;
        bool loop = true;
        while (loop) {
            loop = false;
            for (auto &node : a) {
                if (node == nullptr) continue;
                loop = true;
                ListNode *next_node = node->next;
                cur->next = node;
                node->next = nullptr;
                cur = cur->next;
                node = next_node;
            }
        }
        return dummy->next;
    }
};
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param m int整型
     * @param a ListNode类
     * 指向彩带的起点，val表示当前节点的val，next指向下一个节点
     * @return ListNode类vector
     */
    vector<ListNode *> solve(int m, ListNode *a) {
        vector<vector<ListNode *>> nodes(m);
        ListNode *current = a;
        while (current != nullptr) {
            int color = current->val % m;
            nodes[color].push_back(current);
            current = current->next;
        }

        vector<ListNode *> ans;
        ListNode _dummy(-1), *dummy = &_dummy;
        for (auto &node_vec : nodes) {
            dummy->next = nullptr;
            ListNode *cur = dummy;
            for (auto &node : node_vec) {
                cur->next = node;
                cur = cur->next;
            }
            cur->next = nullptr;
            ans.push_back(dummy->next);
        }
        return ans;
    }
};
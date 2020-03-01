// 删除中间节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

// 使用下一个节点替换当前节点
class Solution {
   public:
    void deleteNode(ListNode *node) {
        ListNode *dNode = node->next;
        node->val = dNode->val, node->next = dNode->next;
        delete dNode;
        return;
    }
};
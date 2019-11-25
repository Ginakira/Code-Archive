#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q, tmp;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            while (!q.empty()) {
                v.push_back(q.front()->val);
                if (q.front()->left) tmp.push(q.front()->left);
                if (q.front()->right) tmp.push(q.front()->right);
                q.pop();
            }
            ans.push_back(v);
            v.clear();
            while (!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
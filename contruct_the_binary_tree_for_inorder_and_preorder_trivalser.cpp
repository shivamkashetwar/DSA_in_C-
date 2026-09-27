class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }

        bool isSameleft = isSameTree(p->left, q->left);
        bool isSameright = isSameTree(p->right, q->right);

        return isSameleft && isSameright && p->val == q->val;
    }
};
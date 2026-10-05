class Solution {
public:
    int po = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1) {
            return leftAns;
        }

        po++;

        if (po == k) {
            return root->val;
        }

        int rightAns = kthSmallest(root->right, k);
        if (rightAns != -1) {
            return rightAns;
        }

        return -1;
    }
};
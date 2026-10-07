class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* sec = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        // Detect violation in BST inorder ordering
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
            }
            sec = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        swap(first->val, sec->val);
    }
};
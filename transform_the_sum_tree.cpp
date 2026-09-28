#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(vector<int>& preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Convert tree into sum tree
int sumtree(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftsum = sumtree(root->left);
    int rightsum = sumtree(root->right);

    root->data += leftsum + rightsum;

    return root->data;
}

int main() {
    vector<int> preorderArray = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node* root = buildTree(preorderArray);

    cout << "Before sum tree: ";
    preorder(root);
    cout << endl;

    sumtree(root);

    cout << "After sum tree: ";
    preorder(root);
    cout << endl;

    return 0;
}
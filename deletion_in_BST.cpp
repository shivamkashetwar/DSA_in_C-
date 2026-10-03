
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* insert(node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* buildbst(vector<int> arr) {
    node* root = NULL;

    for (int val : arr) {
        root = insert(root, val);
    }

    return root;
}

node* getinorder(node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }

    return root;
}

node* delnode(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = delnode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = delnode(root->right, key);
    } 
    else {
        // Case 1: No left child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            node* IS = getinorder(root->right);
            root->data = IS->data;
            root->right = delnode(root->right, IS->data);
        }
    }

    return root;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    node* root = buildbst(arr);

    cout << "Before: ";
    inorder(root);
    cout << endl;

    root = delnode(root, 6);

    cout << "After: ";
    inorder(root);
    cout << endl;

    return 0;
}

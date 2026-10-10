
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

node* rightmostinleftsubtree(node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

node* leftmostinrightsubtree(node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

vector<int> getpredsucc(node* root, int key) {
    node* curr = root;
    node* pre = NULL;
    node* succ = NULL;

    while (curr != NULL) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data) {
            pre = curr;
            curr = curr->right;
        }
        else {
            if (curr->left != NULL) {
                pre = rightmostinleftsubtree(curr->left);
            }

            if (curr->right != NULL) {
                succ = leftmostinrightsubtree(curr->right);
            }

            break;
        }
    }

    int predecessor = (pre != NULL) ? pre->data : -1;
    int successor = (succ != NULL) ? succ->data : -1;

    return {predecessor, successor};
}

int main() {
    node* root = new node(6);

    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(5);
    root->right->left = new node(7);
    root->right->right = new node(9);

    int key = 7;

    vector<int> ans = getpredsucc(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}
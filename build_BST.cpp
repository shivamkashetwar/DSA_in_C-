#include<iostrem>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        data=val;
        left=right=NULL;
    }
};

node* insert(node* root,int val){
    if(root==NULL){
        return new node(val);
        
    }
    
    if(val < root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

node* buildbst(vector<int>arr){
    node* root=NULL;
    
    for(int val : arr){
        root=insert(root,val);
        
    }
    
    return root;
    
}

int main(){
    vactor<int>={3,2,1,5,6,4};
    node* root=buildbst(arr);
    inorder(root);
    cout<<endl;
    
    return 0;
}
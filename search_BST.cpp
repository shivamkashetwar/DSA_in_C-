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

bool search(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    
    if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
    




int main(){
    vactor<int>={3,2,1,5,6,4};
    node* root=buildbst(arr);
   
   cout<< search(root,5);
   
   
   
    return 0;
}
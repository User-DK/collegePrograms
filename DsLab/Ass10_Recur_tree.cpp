#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
};

void inorder1(vector<int> &inorder,TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder1(inorder,root->left);
    inorder.push_back(root->data);
    cout<<root->data<<" ,";
    inorder1(inorder,root->right);
}
void preorder1(vector<int> &preorder,TreeNode *root){
    if(root==NULL){
        return;
    }
    preorder.push_back(root->data);
    cout<<root->data<<" ,";
    preorder1(preorder,root->left);
    preorder1(preorder,root->right);
}
void postorder1(vector<int> &postorder,TreeNode *root){
    if(root==NULL){
        return ;
    }
    postorder1(postorder,root->left);
    postorder1(postorder,root->right);
    postorder.push_back(root->data);
    cout<<root->data<<" ,";
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector <int> inorder;
    cout<<"inorder is : ";
    inorder1(inorder,root);
    vector <int> preorder;
    cout<<"preorder is : ";
    preorder1(preorder,root);
    vector <int> postorder;
    cout<<"postorder is : ";
    postorder1(postorder,root);
}
/*
       1
    /     \
   2       3
  /  \    /  \
4     5   6   7
*/
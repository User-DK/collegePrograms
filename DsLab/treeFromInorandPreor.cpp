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

int search(vector<int>&inorder ,int start, int end, int curr){
    int position;
    for(int i=start;i<=end;i++){
        if(curr==inorder[i]){
            position=i;
            break;
        }
    }
    return position;
}

TreeNode* formTree(vector <int> &preorder,vector <int> &inorder ,int start, int end){
    static int indx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[indx++];
    TreeNode *temp=new TreeNode(curr);
    
    if(start==end){
        return temp;
    }
    int position=search(inorder,start,end,curr);
    temp->left=formTree(preorder,inorder,start,position-1);
    temp->right=formTree(preorder,inorder,position+1,end);
}

void inorderPrint(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<endl;
    inorderPrint(root->right);
}

int main(){
    vector<int> inorder={3,2,1,6,4,5};
    vector<int> preorder={1,2,3,4,6,5};
    TreeNode * root=formTree(preorder,inorder,0,preorder.size()-1);
    inorderPrint(root);
    return 0;
}
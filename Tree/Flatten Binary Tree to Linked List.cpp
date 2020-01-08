// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void linked(TreeNode* A){
    if(A==NULL)
        return;
    linked(A->left);
    //cout<<A->val<<endl;
    TreeNode* temp=A->right;
    TreeNode* temp1=A->left;
    if(temp1!=NULL){
    A->right=A->left; 
    A->left=NULL;
    while(temp1->right!=NULL){
        temp1=temp1->right;
    }
    temp1->right=temp;
    }
    linked(temp);
}
TreeNode* Solution::flatten(TreeNode* A) {
    linked(A);
    return A;
}

// https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int c=0;
void sum(TreeNode* A, int s, int B){
    if(A->left==NULL && A->right ==NULL){
        if((A->val)+s==B)
            c=1; 
        return;}
    if(A->left !=NULL)
        sum(A->left,s+(A->val),B);
    if(A->right != NULL)
        sum(A->right,s+(A->val),B);
        
} 
int Solution::hasPathSum(TreeNode* A, int B) {
    c=0;
    sum(A,0,B);
    return c;
}

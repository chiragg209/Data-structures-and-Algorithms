// https://www.interviewbit.com/problems/2sum-binary-tree/

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
 void sum(TreeNode* A,int B, unordered_map<int, int> &mp){
    if(A==NULL || c==1)
        return;
    if(mp[B-(A->val)]==1){
        c=1;
        return;
    }
    mp[A->val]=1;
    sum(A->left, B, mp);
    if(A->val<B)
        sum(A->right, B, mp);
 }
 
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map <int,int> mp;
    c=0;
    sum(A,B, mp);
    return c;
}
 https://www.interviewbit.com/problems/2sum-binary-tree/

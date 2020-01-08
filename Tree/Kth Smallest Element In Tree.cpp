// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int k=0,c=0,a=0; 
int small(TreeNode* A,int B, vector <int> &C){
    if(c==1)
        return a;
    if(A==NULL)
        return -1;
    C.push_back(A->val);
    small(A->left, B,C);
    if(k==B){
        c=1;
        a=A->val;
        return a;
    }
    k++;
    if(k==B){
        c=1;
        a=A->val;
        return a;
    }
    small(A->right, B,C);
} 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector <int> C;
    int e=small(A,B, C);
    sort(C.begin(),C.end());
    return e;
}

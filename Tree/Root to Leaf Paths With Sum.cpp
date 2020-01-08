// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> C;
void sum(TreeNode* A,vector <int> temp,int s, int B){
    if(A->left==NULL && A->right ==NULL){
        temp.push_back(A->val);
        if((A->val)+s==B)
            C.push_back(temp);
        return;}
    temp.push_back(A->val);    
    if(A->left !=NULL)
        sum(A->left,temp,s+(A->val),B);
    if(A->right != NULL)
        sum(A->right,temp,s+(A->val),B);
        
} 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    C.clear();
    vector<int> temp;
    sum(A,temp,0,B);
    return C;
}

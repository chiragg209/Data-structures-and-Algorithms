// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> C;
void sum(TreeNode* A,long long int s){
    if(A->left==NULL && A->right ==NULL){
        s= ((s*10)+(A->val))%1003;
        C.push_back(s);
        return;}
    if(A->left !=NULL)
        sum(A->left,((s*10)+(A->val))%1003);
    if(A->right != NULL)
        sum(A->right,((s*10)+(A->val))%1003);
        
}  
int Solution::sumNumbers(TreeNode* A) {
    C.clear();
    sum(A,0);
    int value=0;
    for(int i=0;i<C.size();i++){
        //cout<<C[i]<<endl;
        value= (value+ C[i])%1003;
    }
    return value;
}

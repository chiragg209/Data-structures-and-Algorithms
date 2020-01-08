// https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

string x="",y="";
void traverse(TreeNode* A, int B, int C, string s){
    if(A==NULL)
        return;
    if(A->val==B)
        x=s;
    if(A->val==C) 
        y=s;
    traverse(A->left,B,C,s+"0");
    traverse(A->right,B,C,s+"1");
}
int  lcax(TreeNode* A, int B, int C){
  return 0;
} 
int Solution::lca(TreeNode* A, int B, int C) {
    if(A==NULL)
        return -1;
    int value=A->val;
    x="",y="";
    lcax(A,B,C);
    traverse(A,B,C,"0");
    //cout<<x<<" "<<y<<endl;
    for(int i=1;i<min(x.length(),y.length());i++){
        if(x[i]==y[i]){
            if(x[i]=='0')
                A=A->left;
            else
                A=A->right;
        value=A->val;    
        }else
            break;
    }
    /*int b=0,c=0;
    if(b==0 || c==0)
        return -1;*/
    if(x=="" || y=="")        
        return -1;   
    return value;
}

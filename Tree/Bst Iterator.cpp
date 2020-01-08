// https://www.interviewbit.com/problems/bst-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *A;
stack <int> mystack; 
vector <int> C;
int i=0;
void traverse(TreeNode *A){
    if(A==NULL)
        return;
    traverse(A->left);    
    C.push_back(A->val);
    traverse(A->right);
}
BSTIterator::BSTIterator(TreeNode *root) {
    A=root;
    C.clear();
    i=0;
    //mystack.push(A->val);
    traverse(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    //if(A->right !=NULL)
      //  return 1;
    if(i==C.size())
        return 0;
    else
        return 1;
}

/** @return the next smallest number */
int BSTIterator::next() {
    i++;
    return C[i-1];
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

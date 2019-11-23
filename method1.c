/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int previousVal=-2147483648;
bool isFirstVal;

bool inorderTraversal(struct TreeNode* root){
    bool out=true;
    //L
    if(root->left) out=out&inorderTraversal(root->left);
    //Root
    if((isFirstVal==true)||(root->val>previousVal)){
        out=out&true;
        previousVal=root->val;isFirstVal=false;
    }else{
        return false;
    }
    //Right
    if(root->right){
        out=out&inorderTraversal(root->right);
    }
    
    return out;
}

bool isValidBST(struct TreeNode* root){
    if(root==NULL) return true;
    previousVal=-2147483648;
    isFirstVal=true;
    return(inorderTraversal(root));   
}


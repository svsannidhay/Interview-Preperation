class Solution {
public:
    void inv(TreeNode *root) {
        TreeNode *left = root->left;
        root->left = root->right;
        root->right = left;
        if(root->left != NULL) inv(root->left);
        if(root->right != NULL) inv(root->right);
        return;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        if(root != NULL) inv(root);
        
        return root;
    }
};
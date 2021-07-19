class Solution {
public:
    int solve(TreeNode * root,int &res) {
        if(root == NULL) return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        if(res == INT_MIN) res = max(l + r + root->val,max(root->val,max(l + root->val, r + root->val)));
        else res = max(res, max(l + r + root->val,max(root->val,max(l + root->val, r + root->val)))  );
        
        return max(root->val, root -> val + (max(l , r)));
        
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
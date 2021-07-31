class Solution
{
    public:
    
    int dfs(Node *root,bool &ans) {
        if(root == NULL) return 0;
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        if(root->data != left + right && !(root->left == NULL && root->right == NULL)) ans = false;
        
        return left + right + root->data;
        
    }
    
    bool isSumTree(Node* root)
    {
        bool ans = true;
        dfs(root,ans);
        return ans;
    }
};
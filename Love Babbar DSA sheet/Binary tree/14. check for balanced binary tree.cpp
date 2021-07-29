// DP ON TREE 
int dfs(Node *root,bool & ans) {
    if(root == NULL) return 0;
    int left = dfs(root->left,ans);
    int right = dfs(root->right,ans);
    if(abs(left-right) > 1) ans = false;
    return max(left,right) + 1;
}

bool isBalanced(Node *root) {
    bool ans = true;
    dfs(root,ans);
    return ans;
}
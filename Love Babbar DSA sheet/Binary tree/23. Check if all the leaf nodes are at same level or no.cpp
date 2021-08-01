class Solution{
  public:

    void dfs(Node *root,int curr_d,int &l_depth,bool &ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(curr_d != l_depth && l_depth != -1) ans = false;
            else l_depth = curr_d;
        }
        dfs(root->left,curr_d + 1,l_depth,ans);
        dfs(root->right,curr_d + 1,l_depth,ans);
        return;
    }

    bool check(Node *root) {
        int l_depth = -1;
        bool ans = true;
        dfs(root,0,l_depth,ans);
        return ans;
    }
};

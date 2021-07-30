class Solution {
public:

    void dfs_left_biased(Node *root,vector<int> &left) {
        if(root == NULL) return;
        if(!(root->left == NULL && root->right == NULL)) left.push_back(root->data);
        if(root->left != NULL) dfs_left_biased(root->left,left);
        else dfs_left_biased(root->right,left);
    }
    
    void dfs_right_biased(Node *root,vector<int> &right) {
        if(root == NULL) return;
        if(!(root->left == NULL && root->right == NULL)) right.push_back(root->data);
        if(root->right != NULL) dfs_right_biased(root->right,right);
        else dfs_right_biased(root->left,right);
    }
    
    void dfs(Node *root ,vector<int> &leafs) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) leafs.push_back(root->data);
        if(root->left != NULL) dfs(root->left,leafs);
        if(root->right != NULL) dfs(root->right,leafs);
    }
    
    vector <int> printBoundary(Node *root) {
        vector<int> left;
        vector<int> right;
        vector<int> leafs;
        if(root != NULL) dfs_left_biased(root->left,left);
        if(root != NULL) dfs_right_biased(root->right,right);
        dfs(root,leafs);
        reverse(right.begin(),right.end());
        vector<int> ans;
        if(root != NULL) ans.push_back(root->data);
        for(auto i:left) ans.push_back(i);
        for(auto i:leafs) ans.push_back(i); 
        for(auto i:right) ans.push_back(i);
        return ans;
    }
};
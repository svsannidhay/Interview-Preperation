class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int dfs(Node *root) {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int temp = left + right + root->data;
        root->data = left + right;
        return temp;
    }
    
    void toSumTree(Node *node)
    {
        dfs(node);
    }
};
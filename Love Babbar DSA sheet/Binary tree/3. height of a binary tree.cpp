class Solution{
    public:
    //Function to find the height of a binary tree.
    void dfs(struct Node * current,int curr_d,int &depth) {
        if(current->left == NULL && current->right == NULL) {
            depth = max(depth,curr_d);
        } 
        if(current->left != NULL) dfs(current->left,curr_d + 1,depth);
        if(current->right != NULL) dfs(current->right,curr_d + 1,depth);
    }
    
    int height(struct Node* node)   {
        int depth = -1;
        dfs(node,1,depth);
        return depth;
    }
};
class Solution
{
public:
    void dfs(Node *root,int curr,int depth,int &ans,int &depth_max) {
        if(root == NULL) return;
        curr += root->data;
        if(root->left == NULL && root->right == NULL) {
            if(depth > depth_max) {
                ans = curr;
                depth_max = depth;
            } else if(depth == depth_max) {
                ans = max(ans,curr);
            }
        }
        dfs(root->left,curr,depth + 1,ans,depth_max);
        dfs(root->right,curr,depth + 1,ans,depth_max);
        return;
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0;
        int depth_max = -1;
        dfs(root,0,0,sum,depth_max);
        return sum;
    }
};

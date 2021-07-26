// METHOD 1 
/*
  dp on trees
*/
class Solution {
  public:
    // Function to return the diameter of a Binary Tree. 
    
    int solve_dp(Node *root,int &ans) {
        if(root == NULL) return 0;
        int left = solve_dp(root->left,ans);
        int right = solve_dp(root->right,ans);
        
        ans = max(ans,1 + left + right);
        
        return 1 + max(left,right);
        
    }
    
    int diameter(Node* root) {
        int ans = -1;
        solve_dp(root,ans);
        return ans;
        
    }
};
// Method 2 DFS
/*
 
*/
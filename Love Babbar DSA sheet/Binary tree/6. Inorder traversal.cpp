// Recursive solution 
class Solution {
public:
    
    void dfs(TreeNode *root,vector<int> &arr) {
        if(root == NULL) return;
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};
// Iterative

class Solution {
public:    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode * curr = root;
        while(!st.empty() || curr != NULL) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
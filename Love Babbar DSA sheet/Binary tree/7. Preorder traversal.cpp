// Recursive

class Solution {
public:
    void dfs(TreeNode * root,vector<int> &ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};


// ITERATIVE 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode * curr = root;
        vector<int> ans;
        while(!st.empty() || curr != NULL) {
            if(curr != NULL) {
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return ans;
    }
};
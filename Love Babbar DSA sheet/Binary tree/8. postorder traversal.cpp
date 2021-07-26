// Recursive 

public:
    
    void dfs(TreeNode *root,vector<int> &ans) {
        if(root == NULL) return;
        dfs(root->left,ans);
        dfs(root->right,ans);
        ans.push_back(root->val);
        return;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};

// ITERATIVE 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode * curr = root;
        vector<int> ans;
        while(!st.empty() || curr!= NULL) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
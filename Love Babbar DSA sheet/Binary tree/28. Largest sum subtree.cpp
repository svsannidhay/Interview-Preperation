class Solution {
public:
    
    int dfs(TreeNode* root,unordered_map<int,int> &mapit) {
        if(root == NULL) return 0;
        int left = dfs(root->left,mapit);
        int right = dfs(root->right,mapit);
        
        mapit[root->val + left + right]++;
        
        return root->val + left + right;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mapit;
        dfs(root,mapit);
        int max_freq = -1;
        for(auto it = mapit.begin();it != mapit.end();it++) max_freq = max(max_freq,it->second);
        vector<int> ans;
        for(auto it = mapit.begin();it != mapit.end();it++) {
            if(it->second == max_freq) ans.push_back(it->first);
        }
        return ans;
    }
};
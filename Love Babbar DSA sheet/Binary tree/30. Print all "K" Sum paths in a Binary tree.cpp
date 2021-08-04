/*

  Slight Variation of the problem

  Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

  Time Complexity : O(N * N)
  Space Complexity: O(1)

*/

class Solution {
public:
    
    void find_path(TreeNode *root,int sum,int curr,int &ans) {
        if(root == NULL) return;
        curr += root->val;
        if(curr == sum) ans++;
        find_path(root->left,sum,curr,ans);
        find_path(root->right,sum,curr,ans);
    }
    
    void dfs(TreeNode *root,int sum,int &ans) {
        if(root == NULL) return;
        
        find_path(root,sum,0,ans);
        
        dfs(root->left,sum,ans);
        dfs(root->right,sum,ans);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        dfs(root,targetSum,ans);
        return ans;
    }
};
/*
  Time Complexity : O(N)
  Space Complexity : O(N)

*/


class Solution {
public:
    
    void dfs(TreeNode *root,int target,int &curr_sum,unordered_map<int,int> &freq,int &ans) {
        if(root == NULL) return;
        
        curr_sum += root->val;
        ans += freq[curr_sum - target];
        freq[curr_sum]++;
        dfs(root->left,target,curr_sum,freq,ans);
        dfs(root->right,target,curr_sum,freq,ans);
        freq[curr_sum]--;
        curr_sum -= root->val;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        int curr_sum = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        dfs(root,targetSum,curr_sum,freq,ans);
        return ans;
    }
};


/*

  Time Complexity : O(N * N)
  Space Complexity : O(N * N)

  Print the k sum paths in a binary tree

*/

class Solution {
public:
    
    void find_path(TreeNode *root,int &target,int &sum,int &ans,vector<int> &current_path) {
        if(root == NULL) return;
        sum += root->val;
        current_path.push_back(root->val);
        if(sum == target) {
            for(auto i:current_path) cout<<i<<" ";
            cout<<"\n";
            ans++;
        }
        find_path(root->left,target,sum,ans,current_path);
        find_path(root->right,target,sum,ans,current_path);
        sum -= root->val;
        current_path.erase(current_path.begin() + current_path.size () - 1);
        return;
    }
    
    void dfs_try(TreeNode *root,int &target,int &ans) {
        if(root == NULL) return;
        
        vector<int> current_path;
        int sum = 0;
        find_path(root,target,sum,ans,current_path);
        
        dfs_try(root->left,target,ans);
        dfs_try(root->right,target,ans);
        return;
        
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        dfs_try(root,targetSum,ans);
        return ans;
    }
};
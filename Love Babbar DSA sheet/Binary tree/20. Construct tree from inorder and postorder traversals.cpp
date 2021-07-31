/*

    Recursive Solution

    Time Complexity : O(N^2) 
    Auxillary Space Complexity : O(N)

*/

class Solution{
    public:
    
    Node * dfs(int in[],int pre[],int l_in,int r_in,int l_pre,int r_pre) {
        Node * current = new Node(pre[l_pre]);
        
        if(r_in < l_in || r_pre < l_pre) return NULL;
            
        int next_l_in_lc,next_r_in_lc;
        int next_l_in_rc,next_r_in_rc;
        next_l_in_lc = l_in;
        next_r_in_rc = r_in;
        for(int i = l_in;i <= r_in; i++) {
            if(in[i] == pre[l_pre]) {
                next_r_in_lc = i - 1;
                next_l_in_rc = i + 1;
                break;
            }
        }
        
        int next_l_pre_lc = l_pre + 1;
        int next_r_pre_lc = l_pre + (next_r_in_lc - next_l_in_lc + 1);
        int next_l_pre_rc = next_r_pre_lc + 1;
        int next_r_pre_rc = r_pre;
        
        current->left = dfs(in,pre,next_l_in_lc,next_r_in_lc,next_l_pre_lc,next_r_pre_lc);
        current->right = dfs(in,pre,next_l_in_rc,next_r_in_rc,next_l_pre_rc,next_r_pre_rc);
        return current;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        Node * root = dfs(in,pre,0,n-1,0,n-1);
        return root;
    }
};

// /
/*
    Can be optmised to O(N) if we use hashmap to store the position of nodes in 
    the inorder array then we don't need to perform linar search

*/

unordered_map<int,int> map_pos;

class Solution{
    public:
    
    Node * dfs(int in[],int pre[],int l_in,int r_in,int l_pre,int r_pre) {
        Node * current = new Node(pre[l_pre]);
        
        if(r_in < l_in || r_pre < l_pre) return NULL;
            
        int next_l_in_lc,next_r_in_lc;
        int next_l_in_rc,next_r_in_rc;
        next_l_in_lc = l_in;
        next_r_in_rc = r_in;
        
        next_r_in_lc = map_pos[pre[l_pre]] - 1;
        next_l_in_rc = map_pos[pre[l_pre]] + 1;
        
        int next_l_pre_lc = l_pre + 1;
        int next_r_pre_lc = l_pre + (next_r_in_lc - next_l_in_lc + 1);
        int next_l_pre_rc = next_r_pre_lc + 1;
        int next_r_pre_rc = r_pre;
        
        current->left = dfs(in,pre,next_l_in_lc,next_r_in_lc,next_l_pre_lc,next_r_pre_lc);
        current->right = dfs(in,pre,next_l_in_rc,next_r_in_rc,next_l_pre_rc,next_r_pre_rc);
        return current;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        for(int i=0;i<n;i++) {
            map_pos[in[i]] = i;
        }
        Node * root = dfs(in,pre,0,n-1,0,n-1);
        return root;
    }
};

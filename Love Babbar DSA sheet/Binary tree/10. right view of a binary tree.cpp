// METHOD 1 
// Iterative
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        queue<Node *> q;
        if(root != NULL) q.push(root);
        
        vector<int> rt;
        
        while(!q.empty()) {
            int level = q.size();
            
            for(int i = 0;i < level - 1;i++) {
                Node * curr = q.front();
                q.pop();
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            Node * curr = q.front();
            q.pop();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            rt.push_back(curr->data);
        }
        return rt;
    }
};

// METHOD 2 
// Recursive 
class Solution
{
    public:
    
    void dfs(Node *root,int depth,int &max_d,vector<int> &rt) {
        if(root == NULL) return;
        if(depth > max_d) {
            max_d = depth;
            rt.push_back(root->data);
        }
        if(root->right != NULL) {
            dfs(root->right,depth+1,max_d,rt);
        }
        if(root->left != NULL) {
            dfs(root->left,depth + 1,max_d,rt);
        }
    }
     
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        vector<int> rt;
        int max_d = -1;
        dfs(root,0,max_d,rt);
        return rt;
    }
};

/*

    Serialize the tree using preorder traversal and use delimiters 
    to sperate node values also use some other delimiter for empty nodes 
    

*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string dfs(Node *root,unordered_map<string,int> &hash) {
        if(root == NULL) return "$,";
        string s;
        s += to_string(root->data);
        if(root->left == NULL && root->right == NULL) {
            return s;
        }
        string left = dfs(root->left,hash);
        string right = dfs(root->right,hash);
        s += ",";
        s += left;
        s += right;
        hash[s]++;
        return s;
    } 

    int dupSub(Node *root) {
        unordered_map<string,int> hash;
        
        dfs(root,hash);
        
        for(auto it  = hash.begin();it != hash.end();it++) {
            if(it->second > 1) 
                return 1;
        }
        
        return 0;
        
    }
};

/* 

    Serialise the tree or each node efficently and then store the 
    frequecies of each serialised subtree 

    ** NOTE : USE DELIMITERS 

*/

string serialise(Node *root,unordered_map< string,int > &hash,vector<Node *> &ans) {
        
    if(root == NULL) return "X";
    
    string curr = to_string(root->data);
    
    string left = serialise(root->left,hash,ans);
    string right = serialise(root->right,hash,ans);
    
    curr += ",";
    curr += left + ",";
    curr += right + ",";
    
    hash[curr]++;
    if(hash[curr] == 2) {
        ans.push_back(root);
    }
    return curr; 
}

vector<Node*> printAllDups(Node* root) {
    unordered_map< string,int>  hash;
    vector<Node *> ans;
    serialise(root,hash,ans);
    return ans;
}

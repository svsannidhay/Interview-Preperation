/*

  Mark the positions whenever we go left cuz we need to have levels that way 
  now dfs works left first then right so they will automatically come in order

*/

void dfs(Node *root,int pos,vector<int> adj[]) {
    if(root == NULL) return;
    adj[pos].push_back(root->data);
    if(root->left != NULL) dfs (root->left,pos+1,adj);
    if(root->right != NULL) dfs(root->right,pos,adj);
    return;
}

vector<int> diagonal(Node *root) {
    vector<int> adj[100005];
    dfs(root,0,adj);
    vector<int> ans;
    for(int i = 0; i< 100000; i++) {
        for(int j = 0;j < adj[i].size(); j++) {
            ans.push_back(adj[i][j]);
        }
    }
    return ans;
}
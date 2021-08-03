pair<bool,bool> find_lca(Node *root,int a,int b,Node **LCA) {
    if(root == NULL) return make_pair(0,0);
    
    pair<bool,bool> l = find_lca(root->left,a,b,LCA);
    pair<bool,bool> r = find_lca(root->right,a,b,LCA);
    
    pair<bool,bool> current = make_pair((l.first || r.first),(l.second || r.second));
    
    
    if((l.first && r.second) || (l.second && r.first)) *LCA = root;
    
    
    if(root->data == a) {
        current.first = true; 
        if(current.second) *LCA = root;
    }
    
    if(root->data == b) {
        current.second = true;
        if(current.first) *LCA = root;
    }
    
    return current;
}
 
void dfs_dist(Node *root,int depth,int &dist,int target) {
    if(root == NULL) return;
    if(root->data == target) {
        dist = depth;
        return;
    }
    dfs_dist(root->left,depth+1,dist,target);
    dfs_dist(root->right,depth+1,dist,target);
} 
 

int findDist(Node* root, int a, int b) {    
    Node * LCA = NULL;
    find_lca(root,a,b,&LCA);
    int dis1,dis2;
    dfs_dist(LCA,0,dis1,a);
    dfs_dist(LCA,0,dis2,b);
    return dis1 + dis2;
}
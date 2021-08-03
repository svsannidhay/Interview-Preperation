/*

  Time Complexity : O(N)
  Space Compexity : O(1)

  

*/

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    pair< bool,bool > find_lca(Node *root,int &n1,int &n2,Node ** LCA) {
        if(root == NULL) return make_pair(0,0);
        pair<bool,bool> l = find_lca(root->left,n1,n2,LCA);
        pair<bool,bool> r = find_lca(root->right,n1,n2,LCA);
        
        pair<bool,bool> current = make_pair( (l.first || r.first),(l.second || r.second) );
        
        
        if( (l.first && r.second) || (l.second && r.first) )  {
            *LCA = root; 
        }
        
        if(root->data == n1) {
            current.first = true;
            if(current.second) *LCA = root;
        }
        if(root->data == n2) {
            current.second = true;
            if(current.first) *LCA = root;
        }
        
        
        return current;
    }
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        Node * LCA = NULL;
        find_lca(root,n1,n2,&LCA);
        return LCA;
        
    }
};
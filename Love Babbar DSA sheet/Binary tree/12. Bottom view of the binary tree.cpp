#define offset 100000
#define mp(x,y) make_pair(x,y)

class Solution {
  public:
  
    void dfs(Node *root,int pos,int depth,pair<int,int> cache[]) {
        if(root == NULL) return;
        // cout<<root->data<<" "<<pos<<"\n";
        if(cache[pos + offset].first == -1) {
            cache[pos+offset] = mp(root->data,depth);
        } else {
            if(depth >= cache[pos + offset].second) {
                cache[pos+offset] = mp(root->data,depth);
            }
        }
        
        if(root->left != NULL) dfs(root->left,pos-1,depth+1,cache);
        if(root->right != NULL) dfs(root->right,pos+1,depth+1,cache); 
    }
  
    vector <int> bottomView(Node *root) {
        pair<int,int> cache[200005];
        for(int i = 0; i < 200005; i++) {
            cache[i] = mp(-1,-1);
        }
        dfs(root,0,0,cache);
        vector<int> bv;
        for(int i = 0; i < 200000; i++) {
            if(cache[i].first != -1) {
                bv.push_back(cache[i].first);
            }
        } 
        return bv;
    }
};
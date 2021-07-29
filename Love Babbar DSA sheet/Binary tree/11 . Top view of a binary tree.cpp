
#define offset 10000
#define mp(x,y) make_pair(x,y)

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void dfs(Node * root,int pos,int depth,pair<int,int> cus_map[]) {
        if(root == NULL) return;
        if(cus_map[pos+offset].first == -1) {
            cus_map[pos+offset] = mp(root->data,depth);
        } else {
            if(cus_map[pos+offset].second > depth) {
                cus_map[pos+offset] = mp(root->data,depth);
            }
        }
        if(root->left != NULL) dfs(root->left,pos-1,depth+1,cus_map);
        if(root->right != NULL) dfs(root->right,pos+1,depth+1,cus_map);
        return;
    }
    vector<int> topView(Node *root)
    {
        pair<int,int> cus_map[200005];
        for(int i =0 ;i < 200000; i++) {
            cus_map[i] = mp(-1,-1);
        }
        vector<int> tv;
        dfs(root,0,0,cus_map);
        for(int i = 0; i<  200000;i++) {
            if(cus_map[i].first != -1) tv.push_back(cus_map[i].first);
        }
        return tv;
    }

};
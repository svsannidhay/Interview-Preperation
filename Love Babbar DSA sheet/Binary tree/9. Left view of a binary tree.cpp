// METHOD 1 
/*

  Using level order traversal and partition the levels now the 
  first element of each level will be in the left view 

  Time Complexity : O(N)
  Space Complexity : O(N) for queue

*/
vector<int> leftView(Node *root) {
    queue<Node *> q;
    int currl = 1;
    bool first = true;
    int nextl = 0;
    if(root != NULL) q.push(root);
    vector<int> lv;
    while(!q.empty()) {
        Node *x = q.front();
        q.pop();
        if(first) {
            lv.push_back(x->data);
            first = false;
        }
        if(currl > 0) {
            if(x->left != NULL) {
                q.push(x->left);
                nextl++;
            }
            if(x->right != NULL) {
                q.push(x->right); 
                nextl++;
            }
            currl--;
        }
        if(currl == 0) {
            currl = nextl;
            nextl = 0;
            first = true;
        }
    }
    return lv;
}



// Recursive Solution 
/*

  Time Complexity : O(N)
  Space Complexity : O(no of nodes in left tree) + due to recursive stack

*/
void dfs(Node *root,int depth,int &max_d,vector<int> &ans) {
    if(root == NULL) return;
    if(depth > max_d) {
        max_d = depth;
        ans.push_back(root->data);
    } 
    if(root->left != NULL) {
        dfs(root->left,depth+1,max_d,ans);
    } 
    if(root->right != NULL) {
        dfs(root->right,depth+1,max_d,ans);
    }
    return;
}  

vector<int> leftView(Node *root) {
    vector<int> lv;
    int depth = 0;
    int max_depth = -1;
    dfs(root,depth,max_depth,lv);
    return lv;
}
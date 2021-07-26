/*

    Say the tree we have is 
         1 
      2    3 
    4   5 

    and we want the output to be 4 5 2 3 1 
    but if we go by usual approach we will get 5 4 3 2 1 
    what are we really missing here 
    Its the order of nodes visited 
    Just visit right node first and then left node you will get 4 5 2 3 1 

*/

vector<int> reverseLevelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()) {
        Node * current = q.front();
        q.pop();
        ans.push_back(current->data);
        if(current->right != NULL) {
            q.push(current->right);
        }
        if(current->left != NULL) {
            q.push(current->left);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
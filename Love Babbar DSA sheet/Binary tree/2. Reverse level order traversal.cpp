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
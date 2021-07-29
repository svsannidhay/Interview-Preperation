//METHOD 1 
/*

  Use the normal level order traversal just keep reversing the alterate levels 

*/
vector <int> zigZagTraversal(Node* root) {
    vector<int> zz;
    deque<Node *> dq;
    int toggle = true;
    if(root != NULL)   dq.push_back(root);
    while(!dq.empty()) {
        int level_size = dq.size();
        vector<int> order;
        for(int i = 0; i < level_size;i++) {
            Node * current = dq.front();
            dq.pop_front();
            order.push_back(current->data);
            if(current->left != NULL) dq.push_back(current->left);
            if(current->right != NULL) dq.push_back(current->right); 
        }
        if(toggle) {
            for(auto i:order) zz.push_back(i);
            toggle = false;
        } else {
            reverse(order.begin(),order.end());
            for(auto i:order) zz.push_back(i);
            toggle = true;
        }
    }
    return zz;
}

// METHOD 2 
/*

  To use Deque but remeber to use swap children trick

*/

vector <int> zigZagTraversal(Node* root) {
    vector<int> zz;
    deque<Node *> q;
    int toggle = true;
    if(root != NULL)   q.push_back(root);
    while(!q.empty()) {
        int level_size = q.size();
        if(toggle == true) {
            for(int i = 0;i < level_size;i++) {
                Node * curr = q.front();
                q.pop_front();
                zz.push_back(curr->data);
                if(curr->left != NULL) {
                    q.push_back(curr->left);
                } 
                if(curr->right != NULL) {
                    q.push_back(curr->right);
                }
            }    
            toggle = false;
        } else {
            for(int i = 0;i < level_size;i++) {
                Node * curr = q.back();
                q.pop_back();
                zz.push_back(curr->data);
                if(curr->right != NULL) {
                    q.push_front(curr->right);
                }
                if(curr->left != NULL) {
                    q.push_front(curr->left);
                } 
            }     
            toggle = true;
        }
    }
    return zz;
}
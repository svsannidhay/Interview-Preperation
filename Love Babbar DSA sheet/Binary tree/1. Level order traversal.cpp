
class Solution
{
    public:
    vector<int> levelOrder(Node* node) {
      queue<Node*> q;
      q.push(node);
      vector<int> ans;
      while(!q.empty()) {
          Node * current = q.front();
          q.pop();
          ans.push_back(current->data);
          if(current->left != NULL) {
            q.push(current->left);  
          } 
          if(current->right != NULL) {
              q.push(current->right);
          }
      }
      return ans;
    }
};
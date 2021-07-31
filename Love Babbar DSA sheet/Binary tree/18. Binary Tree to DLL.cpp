/*

  Use inorder traversal and keep the track of preveiously visited node 

  Time Complexity: O(N)
  Space Complexity: O(N)

*/
class Solution
{
    public: 
    
    void dfs(Node *root,Node **prev,Node **head) {
        if(root == NULL) return;
        dfs(root->left,prev,head);
        Node * curr = new Node;
        curr->data = root->data;
        curr->left = curr->right = NULL;
        if(*prev != NULL) {
            curr->left = *prev;
            (*prev)->right = curr;
        } else {
            *head = curr;
        }
        *prev = curr;
        dfs(root->right,prev,head);
        return;
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        
        Node *head = NULL;
        Node *prev = NULL;
        dfs(root,&prev,&head);
        return head;
    }
};

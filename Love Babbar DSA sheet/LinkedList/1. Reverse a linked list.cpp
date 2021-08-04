class Solution
{
    public:
    
    Node * reverse_recursive(Node *current,Node *prev) {
        if(current == NULL) {
            return prev;
        }
        Node * next = current->next;
        current->next = prev;
        return reverse_recursive(next,current);
    }
    
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // Node * prev = NULL;
        // Node * curr = head;
        // Node * next = NULL;
        // while(curr != NULL) {
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        return reverse_recursive(head,NULL);
    }
    
};
    
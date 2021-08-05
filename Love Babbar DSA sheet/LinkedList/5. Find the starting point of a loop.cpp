class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        Node *slow = head;
        Node *fast = head;
        
        Node * intersection = NULL;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                intersection = slow;
                break;
            }
        }
        
        if(intersection == NULL) {
            /*
            NO loop
            */
        }
        
        Node * entry = head;
        while(slow != entry) {
            slow = slow->next;
            entry = entry->next;
        }
        
        cout<<slow->data<<" ";
        
    }
};
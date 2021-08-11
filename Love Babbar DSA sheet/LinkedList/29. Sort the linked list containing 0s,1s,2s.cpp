lass Solution
{
    Node * findAndAdd(Node **newhead,Node *current,Node **head,int x) {
        Node * search = *head;
        Node * prev = NULL;
        while(search != NULL) {
            Node *next = search-> next;
            if(search->data == x) {
                if(prev == NULL) {
                    *head = search->next;
                } else {
                    prev->next = search->next;
                }
                search->next = NULL;
                Node * found = search;
                search = next;
                if(current == NULL) {
                    * newhead = found;
                    current = *newhead;
                } else {
                    current->next = found;
                    current = current->next;
                }
                
            } else {
                prev = search;
                search = search->next;
            }
        }
        return current;
    } 
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *newhead = NULL;
        Node * current = NULL;
        current = findAndAdd(&newhead,current,&head,0);
        current = findAndAdd(&newhead,current,&head,1);
        current = findAndAdd(&newhead,current,&head,2);
        return newhead;
        
    }
};
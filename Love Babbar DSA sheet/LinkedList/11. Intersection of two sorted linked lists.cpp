Node* findIntersection(Node* head1, Node* head2)
{
    Node * head = NULL;
    Node * current = head;
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    
    while(ptr1 != NULL && ptr2 != NULL) {
        
        while(ptr1 != NULL && ptr1->data < ptr2->data) {
            ptr1 = ptr1->next;
        }
        while(ptr2 != NULL && ptr2->data < ptr1->data) {
            ptr2 = ptr2->next;
        }
        if(ptr1 == NULL || ptr2 == NULL) break;
        if(ptr1->data == ptr2->data) {
            Node * newNode = new Node(ptr1->data);
            if(current == NULL) {
                current = newNode;
                head = current;
            } else {
                current->next = newNode;
                current = current->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return head;
    
}
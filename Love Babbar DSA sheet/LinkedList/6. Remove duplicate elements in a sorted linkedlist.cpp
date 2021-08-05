Node *removeDuplicates(Node *head)
{   
    Node * current = head;

    while(current != NULL) {
        Node * offset = current->next;
        while(offset != NULL && offset->data == current->data) {
            Node * rem = offset;
            offset = offset->next;
            delete(rem);
        }
        current->next = offset;
        current = offset;
    }
        
    return head;
}
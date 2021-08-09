void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node * slow = head;
    Node * fast = head;
    while( fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head2_ref = slow->next;
    slow->next = head;
    *head1_ref = head;
    Node *traverse = *head2_ref;
    while(traverse->next != head) {
        traverse = traverse->next;
    }
    traverse->next = *head2_ref;
}
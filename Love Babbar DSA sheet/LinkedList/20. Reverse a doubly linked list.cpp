Node* reverseDLL(Node * head)
{
    Node * current = head;
    Node * previous = NULL;
    while(current != NULL) {
        Node * nextnode = current->next;
        current->next = previous;
        current->prev = nextnode;
        previous = current;
        current = nextnode;
    }
    return previous;
}

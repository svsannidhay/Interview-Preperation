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


Node * rev (Node *current,Node * previous) {
    if(current == NULL) return previous;
    Node * next = current->next;
    current->next = previous;
    current->prev = next;
    return rev(next,current);
}

Node* reverseDLL(Node * head)
{
    return rev(head,NULL);
}
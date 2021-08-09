/*
    
    Using brute force 

*/

bool isCircular(Node *head)
{
    Node * traverse = head->next;
    while(traverse != NULL) {
        if(traverse == head) return true;
        traverse = traverse->next;
    }
    return false;
}

/*
    
    Using fast and slow pointers

*/

// bool isCircular(Node *head)
// {
//     Node * slow = head;
//     Node * fast = head;
//     while(fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;
//         slow = slow->next;
//         if(fast == slow) return true;
//     }
//     return false;
// }
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    //Merge two sorted linked lists
    Node *merge (Node *head1,Node *head2) {
        Node * head = NULL;
        Node * current = head;
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                if(head == NULL) {
                    head = head1;
                    current = head;
                } else {
                    current->next = head1;
                    current = current->next;
                }
                head1 = head1->next;
            } else {
                if(head == NULL) {
                    head = head2;
                    current = head;
                } else {
                    current->next = head2;
                    current = current->next;
                }
                head2 = head2->next;
            }
        }
        while(head1 != NULL) {
            current->next = head1;
            current = current->next;
            head1 = head1->next;
        } 
        while(head2 != NULL) {
            current->next = head2;
            current = current->next;
            head2 = head2->next;
        } 
        return head;
    }
    
    
    // Returns Pointer to the mid of the linked list between head and tail 
    Node * findMid(Node * head,Node *tail) {
        Node * slow = head;
        Node * fast = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    // Recursive mergeSort function
    Node *merge_Sort(Node * head,Node * tail) {
        if(head == tail) {
            Node * base_case = new Node(head->data);
            // cout<<base_case->data<<"\n";
            return base_case;
        }
        Node * mid = findMid(head,tail);
        Node * left = merge_Sort(head,mid);
        Node * right = merge_Sort(mid->next,tail);
        return merge(left,right);
    }
    
    Node* mergeSort(Node* head) {
        Node * tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        return merge_Sort(head,tail);
    }
};
class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node * findMid(Node * head)  {
        Node * slow = head;
        Node * fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node * rev(Node * current,Node * prev) {
        if(current == NULL) return prev;
        Node * next = current->next; 
        current->next = prev;
        return rev(next,current);
    }
    
    bool isPalindrome(Node *head)
    {
        Node * mid = findMid(head);
        Node * rev_half = rev(mid->next,NULL);
        
        Node *p1 = head;
        Node *p2 = rev_half;
        
        while(p2 != NULL) {
            if(p1->data != p2->data) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
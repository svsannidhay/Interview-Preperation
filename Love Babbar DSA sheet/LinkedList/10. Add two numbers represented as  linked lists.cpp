/*

  Logic : Reverse both the linked lists now maintain a carry and create the answer 
          Reverse the answer that will be the result.

*/
class Solution
{
    public:
    
    Node * rev(Node *head) {
        Node *prev = NULL;
        Node * curr = head;
        while(curr != NULL) {
            Node * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        Node * fr = rev(first);
        Node * sr = rev(second);
        
        Node * result = NULL;
        Node * move;
        int carry = 0;
        
        while(fr != NULL || sr != NULL || carry != 0) {
            int currval = 0;
            if(fr != NULL) {
                currval += fr->data;
                fr = fr->next;
            }
            if(sr != NULL) {
                currval += sr->data;
                sr = sr->next;
            }
            currval += carry;
            carry = currval / 10;
            Node *current = new Node(currval % 10);
            if(result == NULL) {
                result = current;
                move = result;
            } else {
                move->next = current;
                move = move->next;
            }
        }
        
        Node * ans = rev(result);
        
        return ans;
        
    }
};
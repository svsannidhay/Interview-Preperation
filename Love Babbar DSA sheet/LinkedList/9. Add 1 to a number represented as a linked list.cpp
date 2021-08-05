/*

    Logic : Find the last non 9 position add 1 to it and after it make everything 0
    if(there is no non 9 position) insert 1 at the begening of the list 

*/

class Solution
{
    public:
    Node* addOne(Node *head) {
        Node * last_non_nine = NULL;
        Node * move = head;
        while(move != NULL) {
            if(move->data != 9) last_non_nine = move;
            move = move->next;
        }
        
        if(last_non_nine == NULL) {
            Node * start = head;
            while(start != NULL) {
                start->data = 0;
                start = start->next;
            }
            Node * one = new Node(1);
            one->next = head;
            head = one;
            return head;
        }
        last_non_nine->data++;
        last_non_nine = last_non_nine->next;
        while(last_non_nine != NULL) {
            last_non_nine->data = 0;
            last_non_nine = last_non_nine->next;
        }
        return head;
    }
};

/*

    Reverse the linked list keep adding one till the carry is there 
    and then reverse again and return.

*/

Node *rev(Node *head) {
    Node * prev = NULL;
    Node * curr = head;
    while(curr != NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution
{
    public:
    Node* addOne(Node *head) {
        Node * reverse_head = rev(head);
        int carry = 1;
        Node *move = reverse_head;
        while(carry != 0) {
            move->data += 1;
            carry = move->data / 10;
            move->data = move->data % 10;
            if(move -> next == NULL) {
                break;
            }
            move = move->next;
        }
        if(carry == 1) {
            Node * one = new Node(1);
            move->next = one;
        }
        Node * newhead = rev(reverse_head);
        return newhead;
    }
};

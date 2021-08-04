/*
    
    Floyd's tortise and hare (Cycle detection)
    Also known as fast pointer and slow pointer

    Time Complexity : O(N)
    Space Complexity : O(1)

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        Node * slow = head;
        Node * fast = head;
        
        Node *intersection = NULL;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                intersection = slow;
                break;
            }
        }
        
        if(intersection == NULL) return;
        
        Node * entry = head;
        
        while(entry != intersection) {
            entry = entry->next;
            intersection = intersection->next;
        }
        
        Node * loop_start = entry;
        
        Node * start = head;
        bool once = false;
        while(start != NULL) {
            if(start->next == loop_start && once == true)  {
                start->next = NULL;
            } else {
                start = start->next;
                if(start == loop_start) once = true;
            }
        }
        
    }
};


/*
    Hashmap solution 
    Time Complexity : O(N)
    Space Complexity: O(N)
    
*/

#include<unordered_map>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        unordered_map<Node *,int> mapit;
        mapit[head]++;
        while(head != NULL) {
            if(mapit[head->next] == 1) {
                head->next = NULL;
            }
            head = head->next;
            mapit[head]++;
        }
    }
};
/*

    Using hashmap 
    Time Complexity : O(N)
    Space Complexity : O(N)

*/
class Solution
{
    public:

    bool detectLoop(Node* head) {
        unordered_map<Node *,int> mapit;
        while(head != NULL) {
            if(mapit[head] == 1) return true;
            mapit[head]++;
            head = head->next;
        }
        return false;
    }
};

/*
    Using fast pointer and slow pointer 
    slow pointer move by 1 
    fast pointer move by 2 
    
    if(slow == fast) => cycle 
    
    rest there is no cycle 
    
*/
class Solution
{
    public:

    bool detectLoop(Node* head) {
        Node * slow = head;
        Node * fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        
    }
};
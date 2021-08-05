/*

    Approach 1 : Using hashmasps 
    
    Time Complexity : O(N)
    Space Complexity: O(1)
    
    Approach 2 : Using merge sort and after sorting the LL we can remove duplicates
    
    Time Complexity : O(NlogN + N) 
    Space Complexity : O(1) 
    
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
        Node *current = head;
        Node *prev = NULL;
        unordered_map<int,int> freq;
        while(current != NULL) {
            if(freq[current->data] == 1) {
                prev->next = current->next;
                Node *del = current;
                current = current->next;
                delete(del);
            } else {
                freq[current->data]++;
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};

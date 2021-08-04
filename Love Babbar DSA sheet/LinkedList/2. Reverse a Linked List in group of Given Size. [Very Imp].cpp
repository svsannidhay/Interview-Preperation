class Solution
{
    public:
    
    node * rev(node * current,node * prev,int &count,int k) {
        if(current == NULL || count >= k) {
            return prev;
        }
        node *next = current->next;
        current->next = prev;
        count++;
        return rev(next,current,count,k);
    }
    
    struct node *reverse (struct node *head, int k) { 
        node * newhead = NULL;
        node * block = head;
        node *next_block = block;
        int offset = 0;
        while(offset < k && next_block != NULL) {
            offset++;
            next_block = next_block->next;
        }
        int count = 0;
        newhead = rev(head,NULL,count,k);
        
        while(block != NULL) {
            node *next_next_block = next_block;
            int offset = 0;
            while(offset < k && next_next_block != NULL) {
                offset++;
                next_next_block = next_next_block->next;
            }
            int count = 0;
            block->next = rev(next_block,NULL,count,k);
            block = next_block;
            next_block = next_next_block;
        }
        
        return newhead;
    }
};
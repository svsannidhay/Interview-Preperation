/*

     Method 1 : Using a hashmap

*/

// int intersectPoint(Node* head1, Node* head2) {
//     unordered_map<Node *,int> freq;
//     while(head1 != NULL) {
//         freq[head1]++;
//         head1 = head1 -> next;
//     }
//     int ans = -1;
//     while(head2 != NULL) {
//         if(freq[head2] == 1) {
//             ans = head2->data;
//             break;
//         }
//         head2 = head2->next;
//     }
//     return ans;
// }

/*
    
    Method 2 : Using length difference between two lists
    
    move the pointer of the longer list by abs(len(l1) - len(l2)) that way 
    we will have both the pointers at the same level then start moving both 
    the first point where they collide will be the answer. 

*/
// int intersectPoint(Node* head1, Node* head2) {
//     int len1 = 0;
//     Node * temp1 = head1;
//     while(temp1 != NULL) {
//         len1++;
//         temp1 = temp1->next;
//     }
//     int len2 = 0;
//     Node * temp2 = head2;
//     while(temp2 != NULL) {
//         len2++;
//         temp2 = temp2->next;
//     }
    
//     int d = abs(len1 - len2);
//     if(len1 > len2) {
//         while(d--) {
//             head1 = head1->next;
//         }
//     } else {
//         while(d--) {
//             head2 = head2->next;
//         }
//     }
    
//     int ans = -1;
//     while(head1 != NULL && head2 != NULL) {
//         if(head1 == head2) {
//             ans = head1->data;
//             break;
//         }
//         head1 = head1->next;
//         head2 = head2->next;
//     }
//     return ans;
// }

/*
    
    Method 3 : We can form a loop by connecting one linked list 
    Now the problem reduces to finding the start node of a loop in a linked 
    list.

*/

int intersectPoint(Node* head1, Node* head2) {
    // form the loop 
    Node *traverse = head1;
    while(traverse->next != NULL) {
        traverse = traverse->next;
    }
    traverse->next = head1;
    // Using fast and slow pointers to find the start of the loop
    Node * slow = head2;
    Node * fast = head2;
    Node * intersection = NULL;
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            intersection = slow;
            break;
        }
    }
    if(intersection == NULL) return -1;
    Node *entry = head2;
    
    while(intersection != entry) {
        intersection = intersection->next;
        entry = entry->next;
    }
    return entry->data;
}


/*

Using Two pointers : 


Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
Traverse through the lists,one node at a time.
When ptr1 reaches the end of a list, then redirect it to the head2.
similarly when ptr2 reaches the end of a list, redirect it the head1.
Once both of them go through reassigning, they will be equidistant from 
 the collision point
If at any node ptr1 meets ptr2, then it is the intersection node.
After second iteration if there is no intersection node it returns NULL.

*/
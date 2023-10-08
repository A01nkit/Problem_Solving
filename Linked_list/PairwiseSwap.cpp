/*
Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
Note: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 
2 1 4 2 6 5 8 7
Explanation: 
After swapping each pair considering (1,2), (2, 4), (5, 6).. so on as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as a 
new linked list.
*/

    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        Node* prev=head;
        Node* curr=head->next;
        Node* result=head->next;
        Node* temp;
              if(curr==NULL)
                 return head;
              temp=curr->next;
              
              curr->next=prev;
              prev->next=temp; 
              curr=prev->next;
        while(curr!=NULL){
            temp=curr->next;
            if(temp==NULL)
               return result;
            
            prev->next=temp;
            curr->next=temp->next;
            temp->next=curr;
            
            prev=curr;
            curr=curr->next;
        }
        return result;
        
    }
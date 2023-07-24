/*Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k 
then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 

Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
*/

struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
       node* curr=head; 
       node* prev=NULL; 
       node* temp=NULL;
       int count=0;
       while(curr!=NULL && count<k){
           temp=curr->next;
           curr->next=prev;
           
           prev=curr;
           curr=temp;
           count++;
       }
       if(temp!=NULL){
           head->next=reverse(temp,k);
       }
       return prev;
       
     
        
    }
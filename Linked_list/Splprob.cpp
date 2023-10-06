/*
Given a linked list, you have to perform the following task:

Extract the alternative nodes starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
Note: Try to solve the problem without using any extra memory.

Example 1:

Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 
10 9 3 9 4 5 1 4
Explanation: 
Alternative nodes in the given linked list are 4,1,5,4. Reversing the alternative nodes from the given list, and then
 appending them to the end of the list results in a list 10->9->3->9->4->5->1->4.
 */
    void rearrange(struct Node *odd)
    {
        //add code here
        Node *t=odd;
        Node *curr=odd->next;
        Node *t2=odd->next;
       
        while(t!=NULL && t2!=NULL && t->next!=NULL && t2->next!=NULL){
            t->next=t2->next;
            t=t->next;
            
            t2->next=t->next;
            t2=t2->next;
        }
        if(t!=NULL)
           t->next=NULL;
        if(t2!=NULL)   
           t2->next=NULL;
        
        Node *prev=NULL;
        Node *temp;

        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        t->next=prev;
        
    }


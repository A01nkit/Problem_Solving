/*
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Example 1:
Input:  LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3

Example 2:
Input:  LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and this function should reverse 
the elements such that the tail becomes the new head and all pointers are pointing in the right order. You need to return the new 
head of the reversed list. The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

*/

    Node* reverseDLL(Node * head)
    {
        //Your code here
        stack<Node*> s;
        
        Node *temp=head;
        while(temp!=NULL){
            Node* tempp=temp->next;
                
            temp->next=NULL;
            temp->prev=NULL;
            s.push(temp);
            
            temp=tempp;
        }
        head=s.top();
        temp=head;
        s.pop();
        while(!s.empty()){
            Node* t=s.top();
            temp->next=t;
            t->prev=temp;
            temp=t;
            
            s.pop();
        }
        return head;
    }
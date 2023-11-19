/*
Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. 
The new linked list should be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Example 1:
Input: LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
Output: 2 4 6

Example 2:
Input: LinkedList1 = 10->20->40->50, LinkedList2 = 15->40
Output: 40

Your Task:
You don't have to take any input of print anything. Your task is to complete the function findIntersection(), which will take head of both 
of the linked lists as input and should find the intersection of two linked list and add all the elements in intersection to the third linked 
list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n, m are the size of the respective linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 10
*/

   Node* findIntersection(Node* head1, Node* head2)
   {
        // code goes here.
        bool flag=true;
        Node* head=NULL;
        Node* temp;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                  //if(head1)
                   head1=head1->next;
            }
            else if(head1-> data > head2->data){
                  //if(head2)
                   head2=head2->next;
            }
            else{
                if(!flag){
                    Node* t=new Node(head1->data);
                    temp->next=t;
                    temp=t;
                }
                else{
                    head=new Node(head1->data);
                    temp=head;
                    flag=false;
                }
                
                   head1=head1->next;
               
                   head2=head2->next;
            }
        }
         return head;
    }
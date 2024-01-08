/*
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the 
resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to 
the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104

*/    
    class compare{
        public:
               bool operator()(Node* a, Node*b){
                   return a->data < b->data;
               }
    };
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(!node1 and !node2)
            return NULL;
        
        priority_queue<Node*, vector<Node*>, compare> heap;
        while(node1!=NULL || node2!=NULL){
            if(node1){
                heap.push(node1);
                node1=node1->next;
            }
            if(node2){
                heap.push(node2);
                node2=node2->next;
            }
        }
        Node* head;
        if(!heap.empty())
            head=heap.top();
        Node* temp=head;
        heap.pop();
        while(!heap.empty()){
            Node* tempnew=heap.top();
            heap.pop();
            temp->next=tempnew;
            temp=tempnew;
        }
        temp->next=NULL;
        return head;
       
        
    }  
/*
Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort 
in both non-decreasing and non-increasing order.

Example 1:
Input:
n = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.

Example 2:
Input:
n = 5
value[] = {9,15,0,-1,0}
Output:
-1 0 0 9 15
15 9 0 0 -1
Explanation: After sorting the given
linked list in both ways, the
resultant list will be -1 0 0 9 15
in non-decreasing order and 
15 9 0 0 -1 in non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list 
using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(logn)

Constraints:
1 <= n <= 104
-105 <= values[i] <= 105
*/

    void merge(vector<Node*> &v, int s, int e){
        int i=s;
        int m=(s+e)/2;
        int j=m+1;
        
        vector<Node*> temp;
        while(i<=m and j<=e){
            if(v[i]->data < v[j]->data){
                temp.push_back(v[i]);
                i++;
            }
            else{
                temp.push_back(v[j]);
                j++;
            }
        }
        while(i<=m)
            temp.push_back(v[i++]);
        while(j<=e)
            temp.push_back(v[j++]);
            
        int k=0;
        for(int idx=s; idx<=e; idx++){
            v[idx]=temp[k++];
        }
        
        
        return;
    }
    void mergesort(vector<Node*> &v, int s, int e){
        if(s>=e){
            return;
        }
        
        int mid=(s+e)/2;
        mergesort(v,s,mid);
        mergesort(v,mid+1,e);
        
        return merge(v,s,e);
    }
    
    
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(!head or !head->next){
            return head;
        }
        vector<Node*> v;
        Node* t=head;
        while(t!=NULL){
            v.push_back(t);
            t=t->next;
        }
        
       mergesort(v,0,v.size()-1);
        t=v[0];
        t->prev=NULL;
        head=t;
        
        for(int i=1; i<v.size(); i++){
            Node* temp=v[i];
            t->next=temp;
            temp->prev=t;
            t=temp;
        }
        t->next=NULL;
        return head;
        
       
    }
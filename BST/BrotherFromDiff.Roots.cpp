/*
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(),
 that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output: 3
Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)
*/

class Solution
{
public:
    void check(Node* root, int target, int &count){
        if(root==NULL){
            return;
        }
        
        if(target < root->data)
           check(root->left,target,count);
        else if(target > root->data)
            check(root->right,target,count);
        else if(target==root->data)
            count++;
            
        return;        
    }
    void process(Node* root1, Node* root2, int x, int &count){
        if(root1==NULL)
           return;
           
        process(root1->left,root2,x,count);
        if(x-root1->data > 0)
            check(root2,x-root1->data,count);
        process(root1->right,root2,x,count);    
                
    }
    int countPairs(Node* root1, Node* root2, int x)
    {   int count=0;
        process(root1,root2,x,count);
        
        return count;
        
        

    }
};

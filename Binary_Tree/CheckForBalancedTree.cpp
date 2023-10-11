/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:
Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
*/

 int height(Node* root){
        //base_case
        if(root==NULL)
           return 0;
        
        //rec_case 
        int h1 = height(root->left);  
        int h2 = height(root->right);
        if(h1==-1 || h2==-1)
           return -1;
        if(abs(h1-h2) > 1)
           return -1;
        else
          return 1+max(h1,h2);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here@
        
        if(height(root)==-1)
           return false;
        else
           return true;
       
    }
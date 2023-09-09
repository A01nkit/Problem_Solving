/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 Example 1:

Input:
      1
    /   \
   2     3
Output: 
1 2 3
Explanation:
The converted BST will be 
      2
    /   \
   1     3
*/
    
    
    
    void help(Node *root, set<int> &s){
        if(root==NULL)
           return;
         
        help(root->left, s);   
        s.insert(root->data);
        help(root->right, s); 
         
    }
    void help1(Node *root, queue<int> &q){
        if(root==NULL)
           return;
        help1(root->left, q);
        root->data=q.front();
        q.pop();
        help1(root->right, q);
                
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        set<int> s;
        queue<int> q;
        help(root, s);
        for(auto member : s)
            q.push(member);
            
        help1(root, q);
        
        return root;
        
        
        
        
    }
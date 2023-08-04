Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and 
for all the odd levels we print the node's value from left to right. 
 

Example 1:
Input:
      1
    /   \
   3     2
Output:1 3 2



vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> v;
    if(root==NULL)
       return v;
    else
       v.push_back(root->data);
       
    stack<Node*> s1,s2;
    if(root->right)
       s1.push(root->right);
    if(root->left)   
       s1.push(root->left);   
    while(!s1.empty() || !s2.empty()){
        if(s2.empty()){
           while(!s1.empty()){
               Node* temp=s1.top();
               s1.pop();
               if(temp->left)
                  s2.push(temp->left);
               if(temp->right)
                  s2.push(temp->right); 
               v.push_back(temp->data);
           }
        }
        else{
           while(!s2.empty()){
               Node* temp=s2.top();
               s2.pop();
               if(temp->right)
                  s1.push(temp->right);
               if(temp->left)
                  s1.push(temp->left);      
               v.push_back(temp->data);
           } 
        }
        
    }
    return v;
}
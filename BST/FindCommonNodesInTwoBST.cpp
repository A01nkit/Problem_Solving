/*
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Example 1:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10
*/

void helper1(Node* root, unordered_set<int> &s){
        //base_case
        if(root==NULL)
           return;
        
        //rec_case
        helper1(root->left,s);
        s.insert(root->data);
        helper1(root->right,s);
        
    }
    void helper2(Node* root, unordered_set<int> &s, vector<int> &v){
        //base_case
        if(root==NULL)
           return;
        
        //rec_case
        helper2(root->left,s,v);
        if(s.find(root->data)!=s.end())
           v.push_back(root->data);
        helper2(root->right,s,v);   
           
           
    
           
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> v;
       unordered_set<int> s;
       helper1(root1,s);
       helper2(root2,s,v);
       
       return v;
    }
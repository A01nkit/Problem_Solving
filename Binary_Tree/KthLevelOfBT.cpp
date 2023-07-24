/*Given a binary tree with N nodes. Your task is to print its Kth level.

Input Format

In the function a pointer to the root node of the binary tree is passed.

Output Format

Return a vector containing nodes at Kth level



Input:       
          60             --- Level 0    ,   k=1
         /  \
       50    30          --- Level 1
      /  \   /
    80   10 40           --- Level 2
 

Output: 30 50
*/

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

vector<int> printKthLevel(Node* root, int k){
    // your code goes here
    
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        if(k==0){
            while(!q.empty()){
                v.push_back(temp->key);
                q.pop();
                temp=q.front();
                if(q.front()==NULL)
                  return v;
            }
        } 
        
        while(q.front()!=NULL){
             temp=q.front();  
             if(temp->left!=NULL)
               q.push(temp->left);
             if(temp->right!=NULL)
               q.push(temp->right);
             
             q.pop(); 
        }
        q.pop();
        q.push(NULL);
        k--;   
        
    }
    
 
        
 
}
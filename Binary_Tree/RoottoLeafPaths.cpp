/*
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.


Example 1:
Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3


Example 2:
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 
10 20 40 
10 20 60 
10 30 


Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. 
(All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1<=n<=104
*/

class Solution {
  public:
    void help(Node* root,  vector<vector<int>> &ans, vector<int> &v){
        //base_case
        if(!root)
            return;
            
        //rec_case
        v.push_back(root->data);
        if(!root->left and !root->right){
            ans.push_back(v);
            v.pop_back();
            return;
        }
        help(root->left,ans,v);
        if(!root->right and root->left){
            v.pop_back();
            return;
        }
        help(root->right,ans,v);
        v.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        help(root,ans,v);
        
        return ans;
    }
};
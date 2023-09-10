/* 
  Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
  If K is already present in the BST, don't modify the BST.

Example 1:
Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 
1 2 3 4 6
Explanation: 
After inserting the node 4
Inorder traversal of the above tree will be 1 2 3 4 6.
*/

Node* insert(Node* node, int data) {
        
            // Your code goes here
            if(node==NULL)
               return NULL;
             
            if(node->data < data){
                insert(node->right, data); 
                if(node->right==NULL)
                   node->right=new Node(data);
                
            }
            else if(node->data > data){
                insert(node->left, data);  
                if(node->left==NULL)
                   node->left=new Node(data);
                
            }   
            
                return node;
}                
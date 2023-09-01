/*Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:

Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7
Example 2:

Input:

        10
      /    \
     20     30
    / \  
   40  60
Output: 10 20 30 40 60*/

void printCorner(Node *root)
{

// Your code goes here
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   bool flag=false;
   while(!q.empty()){
       Node *temp=q.front();
       q.pop();
       
       
       if(temp->left)
          q.push(temp->left);
       if(temp->right)
          q.push(temp->right);
        
          
       if(flag){
          cout<<temp->data<<" ";
          flag=false;
          temp=NULL;
       }      
       
       if(q.front()==NULL){
           if(temp)
           cout<<temp->data<<" ";
           q.pop();
           flag=true;
           if(q.empty())
              break;
          
           q.push(NULL);
       }
       
       
       
   }

}
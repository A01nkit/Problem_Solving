/*
Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. 
Return the balanced BST.

Example1:

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


*/

    void helperL(Node* root, vector<Node*> &v, int s, int e){
        int mid=(s+e)/2;
        root->left=v[mid];
        
        //base_case
        if(s==e){
            v[mid]->right=NULL;
            v[mid]->left=NULL;
            return;
        }
        else if(s==mid){
            v[mid]->left=NULL;
            return helperR(v[mid],v,mid+1,e);
            
        }
        else if(e==mid){
            v[mid]->right=NULL;
            return helperL(v[mid],v,s,mid-1);
        }
        
        //rec_case    
        helperL(v[mid],v,s,mid-1);
        helperR(v[mid],v,mid+1,e);
           
    }
   void helperR(Node* root, vector<Node*> &v, int s, int e){
        int mid=(s+e)/2;
        root->right=v[mid];
        
        
        //base_case
        if(s==e){
            v[mid]->left=NULL;
            v[mid]->right=NULL;
            return;
        }
        else if(s==mid){
            v[mid]->left=NULL;
            return helperR(v[mid],v,mid+1,e);
            
        }
        else if(e==mid){
            v[mid]->right=NULL;
            return helperL(v[mid],v,s,mid-1);
        }
        
        //rec_case 
        helperL(v[mid],v,s,mid-1);
        helperR(v[mid],v,mid+1,e);
        
    }
    
    void inorder(Node* root, vector<Node*> &v){
        if(root==NULL)
           return;
           
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<Node*> v;
    	inorder(root,v);
        int mid=v.size()/2;
        int s=0;
        int e=v.size()-1;
        
        root=v[mid];
     
        helperL(root,v,s,mid-1);
        helperR(root,v,mid+1,e);
       
        return root;
    	
    
    
    }	

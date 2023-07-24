
//Time_complexity: O(N*N)
//We are traversing N nodes and also calculating height at every node


int diameter(Node *root){
    //base_case
    if(root == NULL)
       return 0;

    //recursive_case
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));   
}
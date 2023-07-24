/*Given a binary tree with N nodes. Your task is to return the sum of all N nodes.*/
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

int sumBT(Node* root)
{
    // Code here
    return root == NULL ? 0 : sumBT(root->left) + sumBT(root->right) + root->key;
}     
  
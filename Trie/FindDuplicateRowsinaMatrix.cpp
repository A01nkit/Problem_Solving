/*
Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers (0-based) of row which already exists or are repeated.

Example 1:
Input: R = 2, C = 2
matrix[][] = {{1, 0},
             {1, 0}}
Output: 1
Explanation: Row 1 is duplicate of Row 0.

Example 2:
Input: R = 4, C = 3
matrix[][] = {{ 1, 0, 0},
            { 1, 0, 0},
            { 0, 0, 0},
            { 0, 0, 0}}
Output: 1 3 
Explanation: Row 1 and Row 3 are duplicates of Row 0 and 2 respectively. 


Your Task:
You dont need to read input or print anything. Complete the function repeatedRows() that takes the matrix as input
parameter and returns a list of row numbers which are duplicate rows.

Expected Time Complexity: O(R * C)
Expected Auxiliary Space: O(R * C)

Constraints:
1 ≤ R, C ≤ 103
0 ≤ matrix[i][j] ≤ 1
*/

class trie;
class Node{
    int data;
    unordered_map<int,Node*> m;
    bool isTerminal;
public:
    Node(int data){
        this->data=data;
        isTerminal=false;
    }
    friend class trie;
};
class trie{
    Node* root;
public:
    trie(){
        root=new Node('\0');
    }
    void insert(vector<int> v, int N){
        Node* temp=root;
        for(int i=0; i<N; i++){
            if(!temp->m.count(v[i])){
                Node* n=new Node(v[i]);
                temp->m[v[i]]=n;
            }
            
            temp=temp->m[v[i]];
        }
        temp->isTerminal=true;
    }
    bool search(vector<int> v, int N){
        Node* temp=root;
        for(int i=0; i<N; i++){
            if(!temp->m.count(v[i]))
                return false;
            temp=temp->m[v[i]];    
        }
        return temp->isTerminal;
    }
};





class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
       
        int counter=0;
        vector<int> ans;
        trie t;
        for(int i=0; i<M; i++){
            if(t.search(matrix[i],N))
                ans.push_back(counter);
            
            counter++;
            t.insert(matrix[i],N);
        }
        return ans;
      
    } 
};

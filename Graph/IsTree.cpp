/*
You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:
Input: N = 4, M = 3, G = [[0, 1], [1, 2], [1, 3]]
Output: 1
Explanation: Every node is reachable and the graph has no loops, so it is a tree

Example 2:
Input: N = 4, M = 3, G = [[0, 1], [1, 2], [2, 0]]
Output: 0
Explanation: 3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number 
nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 2*105
0 <= M <= 2*105

*/

    void helper(int src, list<int>* l, bool* visit, int &count){
        visit[src]=true;
        count++;
        
        for(int x:l[src]){
            if(!visit[x]){
                helper(x,l,visit,count);
            }
                
        }

        return; 
        
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(m!=n-1)
            return 0;
        int count=0;    
        list<int>* l=new list<int>[n];
        bool* visited=new bool[n]{0};
        
        for(vector<int> v:adj){
            l[v[0]].push_back(v[1]);
            l[v[1]].push_back(v[0]);
            if(v[0]==v[1])
               return 0;
        }
        
        helper(0,l,visited,count);
        if(count==n){
            return 1;
        }
        else{
            return 0;
        }
            
        
    }
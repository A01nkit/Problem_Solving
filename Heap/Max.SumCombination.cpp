/*
Employable by enrolling today! 
Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)
Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation: 
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)
*/

 vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        // code here
        
        vector<int> v;
        priority_queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> s;
        
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        
        q.push({*A.begin()+*B.begin(),{0,0}});
        s.insert({0,0});
        
        while(k--){
            auto p=q.top();
            int sum=p.first;
            int i=p.second.first;
            int j=p.second.second;
            v.push_back(sum);
            q.pop();
            
            if(s.find({i+1,j})==s.end()){
                q.push({A[i+1]+B[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(s.find({i,j+1})==s.end()){
                q.push({A[i]+B[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        
        return v;

    }
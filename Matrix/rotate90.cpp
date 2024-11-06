/*
Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
Output:
7 4 1 
8 5 2
9 6 3
Input: mat[][] = [1 2], [3 4]
Output:
3 1 
4 2
Input: mat[][] = [[1]]
Output:
1
Constraints:
1 ≤ mat.size() ≤ 1000
1 <= mat[][] <= 100
*/

void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    for(int i=0; i<mat.size(); i++){
        for(int j=i; j<mat.size(); j++){
            int x=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=x;
        }
    }
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size()/2; j++){
            int x = mat[i][j];
            mat[i][j] = mat[i][mat.size()-1-j];
            mat[i][mat.size()-1-j] = x;
        }
        
    }
}
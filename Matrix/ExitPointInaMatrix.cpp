/*Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 
you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and 
change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

Example 1:
Input: n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}}
Output: {1, 0}
Explanation: 
Enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..


Example 2:
Input: n = 1, m = 2
matrix = {{0, 0}}
Output: {0, 1}
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains a 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).

Your Task:
You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and 
returns a list containing the exit point.

Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
Expected Space Complexity: O(1)

Constraints:
1 <= n, m <= 100
*/

vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
       
        vector<int> ans;
        bool right=true, left=false, up=false, down=false;
        int i=0, j=0;
        while((i<n and i>-1) and (j<m and j>-1)){
            if(right and !left and !up and !down){
                if(mat[i][j]==0){
                    j++;
                } 
                else{
                    mat[i][j]=0;
                    i++;
                    right=false;
                    down=true;
                }
            }
            else if(!right and left and !up and !down){
                if(mat[i][j]==0){
                    j--;
                } 
                else{
                    mat[i][j]=0;
                    i--;
                    left=false;
                    up=true;
                }
            }
            else if(!right and !left and up and !down){
                if(mat[i][j]==0){
                    i--;
                } 
                else{
                    mat[i][j]=0;
                    j++;
                    up=false;
                    right=true;
                }
            }
            else if(!right and !left and !up and down){
                if(mat[i][j]==0){
                    i++;
                } 
                else{
                    mat[i][j]=0;
                    j--;
                    left=true;
                    down=false;
                }
            }
        }
        
        if(i<0){
            ans.push_back(++i);
            
        }
        else if(i>=n){
            ans.push_back(--i);
        }
        else{
            ans.push_back(i);
        }
        
        if(j<0){
            ans.push_back(++j);
        }
        else if(j>=m){
            ans.push_back(--j);
        }
        else{
            ans.push_back(j);
        }
        
        
        return ans;
}
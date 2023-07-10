/*Write a program to find the transpose of a square matrix of size N*N. Transpose of a matrix is obtained by changing rows 
to columns and columns to rows.*/

void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here
        vector<vector<int>> v = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[j][i] = matrix[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = v[i][j];
            }
        }
    }
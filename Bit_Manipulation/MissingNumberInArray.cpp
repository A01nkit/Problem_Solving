/*Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
*/
 int missingNumber(vector<int>& array, int n) {
        // Your code goes here
       int a = 1;
       for(int i=2; i<=n; i++){
            a = a ^ i;
       }
          
       for(int i=0; i<array.size(); i++){
           a = a ^ array[i];
       }
        
        return a;
    }
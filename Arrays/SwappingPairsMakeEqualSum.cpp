/*
Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values 
(one value from each array) exists such that swapping the elements of the pair will make the sum of 
two arrays equal.

Note: Return 1 if there exists any such pair otherwise return -1.

Example 1:
Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]


Example 2:
Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
Output: 1
Explanation: We can swap 6 from array a[] and 2 from array b[]
Expected Time Complexity: O(mlogm+nlogn).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n, m ≤ 106
0 <= a[i], b[i] <= 105
*/

    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        
        long long int suma=0, sumb=0;
        for(int i=0; i<n; i++)
            suma+=a[i];
        for(int i=0; i<m; i++)
            sumb+=b[i];
            
        int i=0, j=0;
        while(i<n and j<m){
            //cout<<i<<" "<<j<<endl;
            
            long long int x=suma-a[i]+b[j];
            long long int y=sumb-b[j]+a[i];
            if(x==y)
                return 1;
            else if(x<y)
                j++;
            else
                i++;
                
        }
        
        
        return -1;
        
        
    }
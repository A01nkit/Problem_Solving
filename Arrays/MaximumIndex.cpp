/*
Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of
arr[i] <= arr[j].

Sample Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Sample Output: 
6
*/
///worst case time complexity O(N);





int arraySortedOrNot(int arr[], int n)
{
    // Array has one or no element or the
    // rest are already checked and approved.
    if (n == 1 || n == 0)
        return 1;
 
    // Unsorted pair found (Equal values allowed)
    if (arr[n - 1] > arr[n - 2])
        return 0;
 
    // Last pair was sorted
    // Keep on checking
    return arraySortedOrNot(arr, n - 1);
}
int maxIndexDiff(int arr[], int n) {
        // code here
    int i = 0;
    int j=n-1;
    int u=j;
    int ans=0;
    if(arraySortedOrNot(arr, n))
       return ans;
    while(i<j){
          for(int k=0; k<u; k++){
              if(arr[k]<=arr[j] && ans<=(j-k)){
                 ans=j-k;
                 u=k;
                 break;
              }
          }
          j--;
          if((j-i) <= ans)
             return ans;
   }
    return ans;
    
}
/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.

Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/


class Solution {
  public:
    // Function returns the second
    // largest elements
    
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        //configuring the first and second element as per initial.
        int first, second;
        if(arr[0] > arr[1]){
            first = arr[0];
            second = arr[1];
        }
        else{
            first = arr[1];
            second = arr[0];
        }
        
        bool flag = true;
        
        if(arr[1]!=arr[0])
            flag = false;
            
        for(int i=2; i<arr.size(); i++){
            if(arr[i]!=arr[i-1])
                flag=false;
                
            if(arr[i] > first){
                second = first;
                first = arr[i];
            }
            else if((arr[i] > second and arr[i]!=first) or (first==second and second > arr[i])){
                second = arr[i];
            }
        }
        
        
        if(first == second and flag){
            return -1;
        }
        else{
            return second;
        }
    }
};
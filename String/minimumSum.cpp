/*
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two 
numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. 
Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.

Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.

Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.


Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9


*/

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        string ans;
        int carry=0;
        for(int i=arr.size()-1; i>=1; i-=2){
            int x = carry+arr[i]+arr[i-1];
            
            ans.append(to_string(x%10));
            carry = x/10;
        }
        //if arr is odd
        if(arr.size()%2){
            int x = carry+arr[0];
            ans.append(to_string(x%10));
            if(x/10){
                ans.append(to_string(x/10));
            }
        }
        else if(carry){
            ans.append(to_string(carry));
        }
    
        reverse(ans.begin(), ans.end());
        int pointer = 0;
        if(ans[0]=='0')
            pointer++;
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]=='0' and ans[i]==ans[i+1]){
                pointer++;
            }
            else{
                break;
            }
        }
        
        if(pointer!=-1)
            ans.erase(ans.begin(), ans.begin()+pointer);
        
        return ans;
    }
};
/*
Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in 
the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.

Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.

Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109
*/

//APPROACH 1---> Brute force: using set
//APPROACH 2---> Optimal: using 2 pointers



class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> ans;
        
        int s1=a.size(), s2=b.size();
        int i=0, j=0;
        
        while(i<s1 and j<s2){
            if(a[i] < b[j]){//a < b
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j]){//a > b
                ans.push_back(b[j]);
                j++;
            }
            else{//a == b
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        for(int k=i; k<a.size(); k++){
            ans.push_back(a[k]);
        }
        for(int k=j; k<b.size(); k++){
            ans.push_back(b[k]);
        }
            
            
        return ans;    
    }
};
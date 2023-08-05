In this challenge, we are given an array and we need to find out the length of longest subarray whose sum is equal to given integer K.

Sample Input:
arr = { 0,-2,1,2,3,4,5,15,10,5 }
K = 15

Sample output:
5

Explanation:
The following subarray has the sum 15 and is the longest.
1,2,3,4,5

Expected Complexity:
O(N)

Hint:
Use prefix sums + unordered_map.

int longestSubarrayKSum(vector<int> arr,int k){
    // your code goes here
    unordered_map<int, int> m;
    int sum = 0;
    int len = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum == k)
           len = max(len,i+1);
           
        if(m.find(sum - k) != m.end()){
           len = max(len, i - m[sum - k]);
        }  
        else{
           m[sum] = i;
        }
    }
    
    return len;      
}
/*Reduced array size to half
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

Constraints:

1 <= arr.length <= 10^5

1 <= arr[i] <= 10^5

Input Format:

Vector arr[] is passed in the given function.

Output Format:

Return a single integer as required.

Sample Test case:

Input: arr = [3,3,3,3,5,5,5,2,2,7]

Output: 2

Explanation:

Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).

Possible sets of size 2 are {3,5},{3,2},{5,2}.

Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.

*/






int minSetSize(vector<int>& arr) {
        // your code goes here
        int n=arr.size();
        unordered_map<int,int> s;
        priority_queue<int> heap;
        vector<int> v;
        int count=0;
        for(int i=0; i<arr.size(); i++)
            s[arr[i]]++;
            
        for(auto x:s){
            heap.push(x.second);
        } 
        
        
        while(!heap.empty()){
            n-=heap.top();
            heap.pop();
            count++;
            if(n <= (arr.size()/2))
               return count;
        }
        
        
}

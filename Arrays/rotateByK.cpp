/*
Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 
Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.

Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105
*/

/*
This is very first approach that to my mind using queue.
time complexity: O(N)
space complexity: O(d)
*/
class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        if(arr.size() == d)
            return;
        if(d > arr.size()) 
            d = d%arr.size();
            
        queue<int> q;
        for(int i=0; i<d; i++)
            q.push(arr[i]);
        for(int i=d; i<arr.size(); i++)
            arr[i-d] = arr[i];
            
        for(int i = arr.size()-d; i<arr.size(); i++){
            arr[i] = q.front();
            q.pop();
        }    
    }
};


/*
This approach is very optimal
here, we reverse complete array, the we sverse split wise. i.e: from 0->arr.size()-d-1 and from arr.size()-d->arr.size()-1;
time complexity: O(N)
space complexity: O(1)
*/


class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        if(arr.size() == d)
            return;
        if(d > arr.size()) 
            d = d%arr.size();
            
        reverse(arr.begin(), arr.end());
        
        reverse(arr.begin(), arr.begin()+arr.size()-d);
        reverse(arr.begin()+arr.size()-d, arr.end());
    }
};
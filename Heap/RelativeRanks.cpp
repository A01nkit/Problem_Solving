/*
Relative Ranks
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. 
All the scores are guaranteed to be unique.The athletes are placed based on their scores, where the 1st place athlete 
has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines
their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

Input Format:An array score[] is passed in the given function.

Output Format:Return an array of ranks of all athletes.

Constraints:
n == score.length
1 <= n <= 10^4
0 <= score[i] <= 10^6

All the values in score are unique.



Sample Test Cases:
Input 1: score = [5,4,3,2,1]
Output 1: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
*/
vector<string> findRelativeRanks(vector<int>& arr) {
    // your code goes here
    priority_queue<pair<int,int>> heap;
    vector<string> s(arr.size());
    int count=1;
    for(int i=0; i<arr.size(); i++){
        heap.push({arr[i],i});
    }
    
   
    
    while(!heap.empty()){
        if(count==1){
          s[heap.top().second].append("Gold Medal");
          count++;
        }
        else if(count==2){
          s[heap.top().second].append("Silver Medal");
          count++;
        }
        else if(count==3){
          s[heap.top().second].append("Bronze Medal");
          count++;
        }
        else{
          s[heap.top().second].append(to_string(count));
          count++;
        }
        heap.pop();
    }
    
    return s;

}

/*Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Sample Input
{10, 22, 28, 29, 30, 40}, x = 54

Sample Output
22 and 30
*/
#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
    int n = arr.size();
    int s = 0, e = n-1;
    int diff = INT_MAX;
    int leftIdx , rightIdx;

    while(s < e){
        int cs = arr[s] + arr[e];
        if(abs(cs - x) < diff){
            leftIdx = s;
            rightIdx = e;
            diff = abs(cs - x);
        }
        
        if(cs > x){
            e--;
        }
        else{
            s++;
        }
    }

    return {arr[leftIdx],arr{rightIdx}};

    
}   
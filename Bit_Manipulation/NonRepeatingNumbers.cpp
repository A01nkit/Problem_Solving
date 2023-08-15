Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur 
exactly once and are distinct. Find the other two numbers. Return in increasing order.

Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.


vector<int> singleNumber(vector<int> nums){
    int a=0,ans1=0,ans2=0;
    vector<int> v;
    for(int x: nums)
        a=a^x;

    int b=a&(-a);

    for(int x:nums){
        if(b&x)
           ans1=ans1^x;
        else
           ans2=ans2^x;   
    } 
    if(ans1<ans2){
        v.push_back(ans1);
        v.push_back(ans2);
    }    
    else{
        v.push_back(ans2);
        v.push_back(ans1);
    }
    return v;
}
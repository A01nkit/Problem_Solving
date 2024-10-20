/*
A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10. 
If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 

Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.


Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= str.size()<= 105

*/
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size()-1;
        if(str[n]-'0' <= 5){
            str[n] = '0';
            return str;
        }
        else{
            str[n] = '0';
            int carry = 1;
            int i = n-1;
            while(i>=0){
                if((str[i]-'0'+carry) > 9){
                    carry = 1;
                    str[i] = '0';
                }
                else{
                    str[i] = char(str[i]+carry);
                    carry = 0;
                }
                i--;
            }
            
            if(carry==1){
                str.insert(str.begin(),'1');
            }
        }
        
        
        return str;
    }
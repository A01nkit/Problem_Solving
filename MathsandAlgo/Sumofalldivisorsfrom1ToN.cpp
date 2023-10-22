/*
Given a positive integer N., The task is to find the value of Σi from 1 to N F(i) where function F(i) for the number i is 
defined as the sum of all divisors of i.

Example 1:

Input:N = 4
Output:15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15
*/

 long long sumOfDivisors(int N)
    {
        // Write Your Code here
        int counter=1;
        long long int sum=0;
        while(counter <= N){
            sum += (N/counter)*counter;
            counter++;
        }
        return sum;
        
       
    }
/*
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of 
the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. 

Example 1:

Input:
price = [10,7,19]
k = 45
Output: 
4
Explanation: 
A customer purchases 1 stock on day 1, 2 stocks on day 2 and 1 stock on day 3 for 10, 7 * 2 = 14 and 19 respectively. Hence, total amount is
 10 + 14 + 19 = 43 and number of stocks purchased is 4.
Example 2:

Input: 
price = [7,10,4]
k = 100
Output: 
6
Explanation:
Buy on all 3 days.

*/




    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        set<pair<int,int>> s;
        int count=0;
        for(int i=0; i<n; i++){
            s.insert({price[i], i+1});
        }
        
        for(pair<int,int> x:s){
            if(k<x.first){
                break;
            }
            for(int i=x.second; i>0; i--){
                if(k>=i*x.first){
                    k-=i*x.first;
                    count+=i;
                    break;
                }
            }
        }
        return count;
        
    }
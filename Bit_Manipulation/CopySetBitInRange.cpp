/*Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31.
 You have to copy the set bits of 'Y' in the range L to R in 'X'.
Return this modified X.

Note: Range count will be from Right to Left & start from 1.*/



int setSetBit(int x, int y, int l, int r){
        // code here
        int a = (~0) << (l-1);
        int b = (1 << r) - 1;
        if(r==32)
           b = ~0;
        int c=   (a & b) & y;
        return c|x;
        
           
}
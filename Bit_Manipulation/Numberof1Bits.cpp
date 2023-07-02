/*Given a positive integer N, print count of set bits in it. */

int setBits(int N) {
        // Write Your Code here
        int q = 0;
        while(N){
            if(N & 1)
               q++;
            N = N >> 1;
            
        }
        return q;
        
        
    }



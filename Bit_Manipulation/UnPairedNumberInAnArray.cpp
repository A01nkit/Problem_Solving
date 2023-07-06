/*Array of integer is given in which each number has its pair exist return the value of unpaired number*/


int Xoring(int arr[]){
    int x = 0;
    for(auto u : arr){
        x ^= u;
    }
    return x;
}
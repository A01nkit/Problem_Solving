/*Array of integer is given in which each number has its pair exist return the value of unpaired number*/



int Xoring(int arr[]){
    int x = 0;
    for(int i=0; i<arr.size(); i++){
        x ^= arr[i];
    }
    return x;
}
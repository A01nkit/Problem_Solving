/*Array of integer is given in which each number has its pair exist return the value of unpaired number*/



int Xoring(int arr[]){
    int x = 0;
    int n=sizeof(arr)/sizeof(int)
    for(int i=0; i<n; i++){
        x ^= arr[i];
    }
    return x;
}
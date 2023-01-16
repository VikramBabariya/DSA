long maximumSumSubarray(int k, vector<int> &arr , int n){
    int i = 0, j = 0;
    long sum = 0, maxi = 0;
    while(j < n){ // window breaking cond
        if(j-i+1 < k){ // just grow window, dont calulate
            sum += arr[j];
            j++;  
        } 
        else if(j-i+1 == k){
            sum += arr[j];
            maxi = max(maxi, sum); // calulation for window
            // moving window
            sum -= arr[i];
            i++; j++;
        }
    }
    return maxi;
}

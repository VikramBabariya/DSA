/*
s1. identify as sliding window problem (subarr or substring | window size | max or min)
s2. caluclation (identify ds)
s3. ans
s4. slide window
*/


long maximumSumSubarray(int k, vector<int> &arr , int n){
    int i = 0, j = 0;
    long sum = 0, maxi = 0;
    while(j < n){ // window breaking cond
        // calculation
        sum += arr[j];
        if(j-i+1 < k){
            j++;  
        } 
        else if(j-i+1 == k){
            // ans from calc
            maxi = max(maxi, sum);
            // moving window
            sum -= arr[i];
            i++; j++;
        }
    }
    return maxi;
}

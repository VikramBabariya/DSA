

int atMostKZeros(vector<int>& nums, int k) {
    int n = nums.size(), i = 0, j = 0, maxi = 0;
    int zeros = 0;

    while(j < n){
        if(nums[j] == 0) zeros++;

        while(zeros > k){
            if(nums[i] == 0) zeros--;
            i++;
        }
        maxi = max(maxi, j-i+1);
        j++;
    }
    return maxi;
}

int sumAtMostK(vector<int>& nums, int k){
    if(k < 0) return 0;
    int i = 0, j = 0, ans = 0;
    int sum = 0, n = nums.size();

    while(j < n){
        sum += nums[j];

        while(i < n && sum > k){
            sum -= nums[i];
            i++;
        }
        ans += j-i+1;
        j++;
    }
    cout<<ans<<" ";
    return ans;
}


int atMostKDistinct(vector<int>& arr, int k){
    int i = 0, j = 0, ans = 0;
    unordered_map<int,int> mp;
    
    while(j < arr.size()){
        mp[arr[j]]+=1;
        
        while(mp.size() > k){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
            i++;
        }
        
        ans += j-i+1; // prev elemnts of window + last added elemetn in window will create new (j-i+1) subarr
        j++;
    }
    return ans;
}


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


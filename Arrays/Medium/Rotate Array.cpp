void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp = nums;

    int start = n - k;
    for(int i = start; i < n; i++){
        nums[i-start] = nums[i];
    }
    for(auto e : nums) cout<<e<<" ";
    cout<<endl;
    for(int i = 0, j = i + k; i < start; i++, j++){
        nums[j] = temp[i];
    }
}

// sol2 O(1) extra space
void reverse(vector<int>& nums, int i, int j){
    int tmp = 0;       
    while(i < j){
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n < 2){
        return;
    }

    k = k % n;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}

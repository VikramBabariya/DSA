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

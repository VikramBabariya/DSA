void subsets(vector<int>& nums) {
    int n = nums.size(), total = pow(2, n);
    for(int num = 0; num < total; num++){
        vector<int> ss;
        for(int i = 0; i < 32; i++){
            if(num & 1 << i) ss.push_back(nums[i]);
        }
    }
}

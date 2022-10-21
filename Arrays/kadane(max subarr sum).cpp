
//Sol2 Kadane Algorithm | tc:o(N) sc:o(1)
int maxSubArray(vector<int>& nums) {
        int max = nums[0], sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        
        return max;
    }

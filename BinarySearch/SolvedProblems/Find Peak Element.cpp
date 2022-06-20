class Solution {
    
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        long long low = 1, high = n-2;
        while(low <= high){
            long long mid = (low + high)>>1;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if(nums[mid-1] > nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};

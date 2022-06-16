class Solution {
    
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2;
        
        while(low <= high){
            int m = (low + high) >> 1;
            if(nums[m] == nums[m^1]){
                low = m+1;
            }else{
                high = m-1;
            }
        }
        
        return nums[low];
    }
};

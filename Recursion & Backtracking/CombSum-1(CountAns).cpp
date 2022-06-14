// same number can not be taken more than one
class Solution {
    
    int combSumCnt(int i, vector<int> &sol, int &target, vector<int> &nums){
        if(target == 0) return true;
        if(i == nums.size()) return false;
          
  
        if(nums[i] <= target){
            sol.push_back(nums[i]);
            target -= nums[i];
            if(combSumCnt(i+1, sol, target, nums)) return true;
            sol.pop_back();
            target += nums[i];
        }
        return combSumCnt(i+1, sol, target, nums);  
    }
    
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sol;
        return combSumCnt(0, sol, target, nums);
    }
};

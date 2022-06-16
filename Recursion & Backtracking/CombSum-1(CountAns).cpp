// same number can not be taken more than one
class Solution {
    
    int combSumCnt(int i, vector<int> &sol, int &target, vector<int> &nums){
        if(target == 0) return 1;
        if(i == nums.size()) return 0;
          
        int pos1 = 0, pos2 = 0;
        if(nums[i] <= target){
            sol.push_back(nums[i]);
            target -= nums[i];
            pos1 = combSumCnt(i+1, sol, target, nums);
            sol.pop_back();
            target += nums[i];
        }
        pos2 = combSumCnt(i+1, sol, target, nums);  
        return pos1 + pos2; 
    }
    
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sol;
        return combSumCnt(0, sol, target, nums);
    }
};

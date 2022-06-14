// same number can not be taken more than one
class Solution {
    
    void combSumAll(int i, vector<int> &sol, int &target, vector<int> &nums, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(sol);
            return;
        }
        if(i == nums.size()) return;
          
  
        if(nums[i] <= target){
            sol.push_back(nums[i]);
            target -= nums[i];
            combSumAll(i+1, sol, target, nums, ans);
            sol.pop_back();
            target += nums[i];
        }
        combSumAll(i+1, sol, target, nums, ans);  
    }
    
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        combSumAll(0, sol, target, nums, ans);
        return ans;
    }
};

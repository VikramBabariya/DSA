class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        int n = nums.size();
        
        for(int i = 0; i < n; i++) cnt[nums[i]]++;
        
        int it = 0; 
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < cnt[i]; j++, it++){
                nums[it] = i;
            }
        }
    }
};

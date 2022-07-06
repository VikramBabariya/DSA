class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxi = nums[n-1], len = 1, type = 2; // type = 2(both), 1(big), 0(small)
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == maxi) continue;
            
            if(type == 2){
                type = (nums[i] < maxi) ? 1 : 0;
                maxi = nums[i];
                len++;
                cout<<i<<" ";
            }else if(type == 1){
                if(nums[i] > maxi){
                    maxi = nums[i];
                    len++;
                    type = 0;  
                }else maxi = nums[i];
                cout<<i<<" ";
            }else if(type == 0){
                if(nums[i] < maxi){
                    maxi = nums[i];
                    len++;
                    type = 1;
                }else maxi = nums[i];
                cout<<i<<" ";
            }
        }
        return len;
    }
};

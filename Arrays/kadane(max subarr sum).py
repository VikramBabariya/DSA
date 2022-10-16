class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        total, maxi = 0, nums[0]
        
        for i in range(len(nums)):
            total += nums[i]
            maxi = max(maxi, total)
            
            if(total < 0): total = 0
                
        return maxi

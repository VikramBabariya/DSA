class Solution:
    
    def swap(self, i, j, nums: List[int]) -> None:
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
    
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums) 
        if(n <= 1): return # base case 

        p = n-2 #case 
        while(p >= 0 and nums[p] >= nums[p+1]): p -= 1 # finding break point

        if(p >= 0):
            p1 = n-1  # finding first strict greater element 
            while(nums[p1] <= nums[p]): p1-=1
            self.swap(p1, p, nums)
        nums[p+1:] = nums[p+1:][::-1] # reversing

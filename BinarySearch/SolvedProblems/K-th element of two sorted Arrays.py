class Solution:
    def kthElement(self,  nums1, nums2, n1, n2, k):
        if(n2 < n1): return self.kthElement(nums2, nums1, n2, n1, k)
        
        low, high = max(0, k-n2), min(n1, k)
        
        while(low <= high):
            cut1 = (low + high)//2
            cut2 = k - cut1
            
            l1, l2, r1, r2 = -1e9, -1e9, 1e9, 1e9
            if(cut1 > 0): l1 = nums1[cut1-1]
            if(cut2 > 0): l2 = nums2[cut2-1]
            if(cut1 < n1): r1 = nums1[cut1]
            if(cut2 < n2): r2 = nums2[cut2]
            
            if(l1 <= r2 and l2 <= r1):
                return max(l1, l2)
            elif(l1 > r2):
                high = cut1 - 1
            else:
                low = cut1 + 1
                
        return -1

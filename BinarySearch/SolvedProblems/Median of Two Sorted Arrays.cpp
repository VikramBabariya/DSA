class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if(n2 < n1): return self.findMedianSortedArrays(nums2, nums1)
        
        half = (n1 + n2 + 1)//2
        print(half)
        low, high = 0, n1
        
        while(low <= high):
            cut1 = (low + high)//2
            cut2 = half - cut1
            
            l1, l2, r1, r2 = -1e9, -1e9, 1e9, 1e9
            if(cut1 > 0): l1 = nums1[cut1-1]
            if(cut2 > 0): l2 = nums2[cut2-1]
            if(cut1 < n1): r1 = nums1[cut1]
            if(cut2 < n2): r2 = nums2[cut2]
            
            if(l1 <= r2 and l2 <= r1):
                if((n1+n2) % 2 == 0): return (max(l1, l2) + min(r1, r2))/2.0
                else: return max(l1, l2)
            elif(l1 > r2):
                high = cut1 - 1
            else:
                low = cut1 + 1
                
        return 0.0
            

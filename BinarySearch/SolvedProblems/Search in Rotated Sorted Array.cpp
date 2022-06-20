class Solution {
    
    int findPivot(vector<int>& arr){
        int n = arr.size(), l = 0, r = n-1;
        while (l <= r) {
            int mid = (l + r)>>1;
            if(arr[mid] >= arr[0]) l = mid+1;
            else r = mid-1;
        }
        return l == n ? 0 : l;
    }
    
   int bs(int l, int r, int val, vector<int> &arr){
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == val) return mid;
            if (arr[mid] > val) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);
        if(target > nums[n-1]) return bs(0, pivot-1, target, nums); 
        return bs(pivot, n-1, target, nums);  
    }
};

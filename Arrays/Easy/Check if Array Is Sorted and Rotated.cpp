bool check(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while(i <= n-1){
        if(i == n-1) return true;
        if(nums[i] > nums[i+1]) {
            i++;
            break;
        }
        i++;
    }
    while(i <= n-1){
        if(i == n-1) return nums[i] <= nums[0]; 
        if(nums[i] > nums[0] || nums[i] > nums[i+1]) return false;
        i++;
    }
    return true; // will never rich here;
}

//sol2
bool check(vector<int>& A) {
    for (int i = 0, k = 0; i < A.size(); ++i)
        if (A[i] > A[(i + 1) % A.size()] && ++k > 1)
            return false;
    return true;
}

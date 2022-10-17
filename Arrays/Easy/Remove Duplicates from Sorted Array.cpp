int removeDuplicates(vector<int>& nums) {
    int i = 1, n = nums.size();
    int uniqe = 1;

    while(i < n){
        if(nums[i] > nums[i-1]){
            nums[ans] = nums[i];
            uniqe++;
        }
        i++;
    }
    return uniqe;
}

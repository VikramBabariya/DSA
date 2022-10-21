//sol1 Countin Sort | TC: O(2N) SC:O(1)
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


//sol2 Dutch National Flag Algorithm | TC: O(N) SC:O(1)
void sortColors(vector<int>& nums) {

    // initialize variables:
    int low = 0, mid = 0, high = nums.size() - 1;

    // logic:
    while(mid <= high)
    {
        switch(nums[mid])
        {
            case 0: swap(nums[low++], nums[mid++]); break;

            case 1: mid++; break;

            case 2: swap(nums[mid], nums[high--]); break;
        }
    }
}

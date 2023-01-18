int numberOfSubarrays(vector<int>& nums, int k) {
    int i = -1, j = 0, ans = 0;
    queue<int> oddPos;

    while(j < nums.size()){
        if(nums[j] % 2 != 0) oddPos.push(j);

        if(oddPos.size() < k) j++;
        else if(oddPos.size() == k){
            ans += (oddPos.front() - i);
            j++;
        }
        else{
            i = oddPos.front();
            oddPos.pop();
            ans += (oddPos.front() - i);
            j++;
        }
    }
    return ans;
}

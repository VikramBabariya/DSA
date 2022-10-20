int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainSum;
    remainSum.insert({0, 1});
    int n = nums.size();
    int currSum = 0, ans = 0;

    for(int i = 0; i < n; i++){
        currSum += nums[i];
        auto it = remainSum.find(currSum - k);
        if(it != remainSum.end()){
            int cnt = (*it).second;
            ans += cnt;
        }
        remainSum[currSum]++;
    }
    return ans;
}

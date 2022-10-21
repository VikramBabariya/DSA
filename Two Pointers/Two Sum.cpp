vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size(), i = 0, j = n-1;
    vector<pair<int, int>> ordNums;
    for(int i = 0; i < n; i++){
        ordNums.push_back({nums[i], i});
    }
    sort(ordNums.begin(), ordNums.end());

    while(i < j){
        if(ordNums[i].first + ordNums[j].first == target) break;
        if(ordNums[i].first + ordNums[j].first < target) i++;
        else j--;
    }

    vector<int> ans;
    ans.push_back(ordNums[i].second);
    ans.push_back(ordNums[j].second);
    return ans;
}



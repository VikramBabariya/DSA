//sol1 Hashing TC:O(N) SC:O(N)
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counter;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        counter[nums[i]]++;
    }

    for(auto pr : counter){
        if(pr.second > n/2) return pr.first;
    }
    return INT_MAX;
}

//sol2 Moores Voting Algorithm | TC:O(N) SC:O(1)
int majorityElement(vector<int>& nums) {
    int n = nums.size(), cnt = 0, el = -1;

    for(int i = 0; i < n; i++){
        if(cnt == 0)
            el = nums[i];
        if(el == nums[i])
            cnt++;
        else 
            cnt--;
    }
    return el;
}

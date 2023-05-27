/*
link : https://leetcode.com/problems/top-k-frequent-elements/description/
TC : O(nlogk)
SC : k
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> fq;
    for(int i = 0; i < n; i++) fq[nums[i]]++;

    priority_queue<pii, vector<pii>, greater<pii>> minh;
    for(auto &pr: fq){
        minh.push({pr.second,pr.first});
        if(minh.size() > k) minh.pop();
    }

    vector<int> ans;
    while(minh.size()){
        ans.push_back(minh.top().second);
        minh.pop();
    }
    return ans;
}

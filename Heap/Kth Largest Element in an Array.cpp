/*
Problem Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
TC : nlogk
SC: k
*/


int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minh;

    for(auto &num: nums){
        minh.push(num);
        if(minh.size() > k) minh.pop();
    }
    return minh.top();
}

// uses pigen hole principle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 1, high = n;
        while(low < high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(auto e : nums){
                if(e <= mid) cnt++;
            }
            
            if(cnt > mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
